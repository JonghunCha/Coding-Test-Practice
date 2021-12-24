/*
문제 링크 : https://leetcode.com/problems/reverse-words-in-a-string-iii/
간단한 two pointers 문제다.

전체 문자열을 순회하며 공백이 나올 때 마다 reverse를 수행하고 start를 갱신하면 된다.
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