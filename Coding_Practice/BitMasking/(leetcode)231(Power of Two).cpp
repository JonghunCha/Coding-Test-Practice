/*
���� ��ũ : https://leetcode.com/problems/power-of-two/
��Ʈ����ŷ���� �����ϰ� �ذ��� �� �ִ� ������.

�ݺ������ε� �ذ��� �� ������ ��Ʈ����ŷ�� �̿��ϸ� �ξ� �� ������ ª�� �ڵ带 �ۼ��� �� �ִ�.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)  return false;
        return !(n & (n - 1));
    }
};