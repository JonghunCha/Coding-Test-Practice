/*
���� ��ũ : https://leetcode.com/problems/reverse-string/
���� ������ two pointers������.

�ϳ��� ���ڿ��� ����, �ϳ��� ���ڿ��� ���������� 1���ϰ� 1���� ������ index�� �����ϸ� ���ڸ� ���� �ٲ��ָ� �ȴ�.
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