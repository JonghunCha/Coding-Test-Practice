/*
문제 링크 : https://leetcode.com/problems/reverse-string/
정말 간단한 two pointers문제다.

하나는 문자열의 시작, 하나는 문자열의 마지막부터 1더하고 1빼는 식으로 index를 조절하며 문자를 서로 바꿔주면 된다.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for (int a = 0; a < (s.size() / 2); a++) {
            temp = s[a];
            s[a] = s[s.size() - a - 1];
            s[s.size() - a - 1] = temp;
        }
    }
};