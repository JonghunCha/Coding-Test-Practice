/*
���� ��ũ : https://leetcode.com/problems/reverse-words-in-a-string-iii/
������ two pointers ������.

��ü ���ڿ��� ��ȸ�ϸ� ������ ���� �� ���� reverse�� �����ϰ� start�� �����ϸ� �ȴ�.
*/
class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        char temp;
        while (start < s.size()) {
            end++;
            if (s[end] == ' ' || end == s.size()) {
                for (int a = 0; a < (end - start) / 2; a++) {
                    temp = s[start + a];
                    s[start + a] = s[end - a - 1];
                    s[end - a - 1] = temp;
                }
                start = end + 1;
            }
        }
        return s;
    }
};