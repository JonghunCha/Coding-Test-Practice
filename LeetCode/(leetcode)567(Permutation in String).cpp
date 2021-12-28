/*
���� ��ũ : https://leetcode.com/problems/permutation-in-string/
Sliding Window�� �ذ��� �� �ִ� ������.

s2���� s1�� ���� ��ŭ�� ���ڿ��� s1�� permutation���� Ȯ���ϸ� �ȴ�.

������ s1�� permutation�� ��� ������ ���ΰ��ε�, �̴� �ܼ��� s1�� ���̸�ŭ�� ���ڿ��� �� ���ڰ� �� ���� �����ߴ��ķ� ������ �ذ��� �� �ִ�.

���� ��� permutation�� ����� �װͰ� ��ġ�ϴ� ���� �ִ����� ���ϸ� �ξ� �� ���� �ð��� �ɸ� ���̴�.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26], count2[26], len = s1.size(), right = len;
        bool answer;
        //s1�� ���̰� �� �� ��� false ��ȯ
        if (s1.size() > s2.size())   return false;
        for (int a = 0; a < 26; a++) {
            count1[a] = 0;
            count2[a] = 0;
        }
        //�ʱ� count1�� count2 ����
        for (int a = 0; a < s1.size(); a++) {
            count1[s1[a] - 'a']++;
            count2[s2[a] - 'a']++;
        }
        //���� �����ִ� window�� �ٷ� ���� index�� right�̴�.
        while (right <= s2.size()) {
            answer = true;
            for (int a = 0; a < 26; a++) {
                //���� count1�� count2�� �ٸ��ٸ� ���� window�� s1�� permutation�� �ƴϴ�.
                if (count1[a] != count2[a]) {
                    if (right == s2.size())  return false;  //���� window�� ���� ��� false ��ȯ
                    count2[s2[right - len] - 'a']--;    //�������� ���� ������ ����
                    count2[s2[right++] - 'a']++;        //������ �ϳ��� �߰�
                    answer = false;
                    break;
                }
            }
            if (answer)  return answer;
        }
        return false;
    }
};