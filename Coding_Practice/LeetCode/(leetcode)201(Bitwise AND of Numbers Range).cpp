/*
���� ��ũ : https://leetcode.com/problems/bitwise-and-of-numbers-range/
BitMasking���� �ذ��� �� �ִ� ������.

left�� right���̴� ���ӵ� �����̰� left���� right�� ũ��.

���� ��� ���� &���� �ϸ� ���� ��Ʈ���� ������� �� left�� right�� ��ġ�ϴ� ������ ��Ʈ�� ��Ƴ��� �ȴ�.

�ᱹ, left�� right�� ��ġ�� ������ >> ������ ���ְ�, �������� ������ >>������ �� ��ŭ <<������ ���ָ� �ȴ�.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }

        left <<= count;

        return left;
    }
};