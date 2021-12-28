/*
문제 링크 : https://leetcode.com/problems/find-all-anagrams-in-a-string/
Sliding Window로 해결할 수 있는 문제다.

anagram은 결국 사용하는 각 문자들의 갯수가 똑같으면 된다.

모든 입력은 소문자 알파벳이라 하였기에 int[26]짜리 배열을 2개 만들고 문자열 s를 문자열 p길이의 window로 탐색하며 각 알파벳의 갯수가 같은지 확인하면 된다.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int dic_s[26], dic_p[26], start = 0, end = p.size() - 1;
        bool anagram;
        if (s.size() < p.size()) return ret;    //p가 더 큰경우 항상 anagram이 있을 수 없다
        for (int a = 0; a < 26; a++) {
            dic_s[a] = 0;
            dic_p[a] = 0;
        }
        for (int a = 0; a < p.size(); a++) {    //초기 dic_s와 dic_p값 지정
            dic_s[int(s[a] - 'a')]++;
            dic_p[int(p[a] - 'a')]++;
        }
           
        while (end <= s.size() - 1) {   //end가 s배열의 끝에 도달할 때까지 반복
            anagram = true;
            for (int a = 0; a < 26; a++) {  //서로 갯수가 다른 문자가 있다면 anagram이 아님
                if (dic_s[a] != dic_p[a]) {
                    anagram = false;
                    break;
                }
            }

            if (anagram) ret.push_back(start);  //anagram인 경우 정답에 추가
            if (end != s.size() - 1) {  //다음 비교는 맨 앞의 문자의 갯수를 1빼고, 다음 문자의 갯수를 1더한다
                dic_s[s[start++] - 'a']--;
                dic_s[s[++end] - 'a']++;
            }
            else    end++;
        }

        return ret;
    }
};