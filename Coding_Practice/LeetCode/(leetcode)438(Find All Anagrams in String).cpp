/*
���� ��ũ : https://leetcode.com/problems/find-all-anagrams-in-a-string/
Sliding Window�� �ذ��� �� �ִ� ������.

anagram�� �ᱹ ����ϴ� �� ���ڵ��� ������ �Ȱ����� �ȴ�.

��� �Է��� �ҹ��� ���ĺ��̶� �Ͽ��⿡ int[26]¥�� �迭�� 2�� ����� ���ڿ� s�� ���ڿ� p������ window�� Ž���ϸ� �� ���ĺ��� ������ ������ Ȯ���ϸ� �ȴ�.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int dic_s[26], dic_p[26], start = 0, end = p.size() - 1;
        bool anagram;
        if (s.size() < p.size()) return ret;    //p�� �� ū��� �׻� anagram�� ���� �� ����
        for (int a = 0; a < 26; a++) {
            dic_s[a] = 0;
            dic_p[a] = 0;
        }
        for (int a = 0; a < p.size(); a++) {    //�ʱ� dic_s�� dic_p�� ����
            dic_s[int(s[a] - 'a')]++;
            dic_p[int(p[a] - 'a')]++;
        }
           
        while (end <= s.size() - 1) {   //end�� s�迭�� ���� ������ ������ �ݺ�
            anagram = true;
            for (int a = 0; a < 26; a++) {  //���� ������ �ٸ� ���ڰ� �ִٸ� anagram�� �ƴ�
                if (dic_s[a] != dic_p[a]) {
                    anagram = false;
                    break;
                }
            }

            if (anagram) ret.push_back(start);  //anagram�� ��� ���信 �߰�
            if (end != s.size() - 1) {  //���� �񱳴� �� ���� ������ ������ 1����, ���� ������ ������ 1���Ѵ�
                dic_s[s[start++] - 'a']--;
                dic_s[s[++end] - 'a']++;
            }
            else    end++;
        }

        return ret;
    }
};