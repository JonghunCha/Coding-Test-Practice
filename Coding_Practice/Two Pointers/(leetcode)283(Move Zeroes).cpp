/*
���� ��ũ : https://leetcode.com/problems/move-zeroes/
Two Pointers�� �����ϰ� �ذ��� �� �ִ�.

ù ��° �����ʹ� nums�� ���ۺ��� ������ Ž���ϴ� ������ �ϰ� �� ��° �����ʹ� 0�� �ƴ� ���ڰ� �� ��ġ�� index�� ����Ų��.

ù ��° �����Ͱ� 0�� �ƴ� ���ڸ� �߰��� ������ �� ��° �����Ͱ� ����Ű�� ��ġ�� swap�� �ϰ� �� ��° �����ʹ� ���� index�� ����Ű���� �ϸ� �ȴ�.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero_index = 0;
        for (int a = 0; a < nums.size(); a++) {
            if (nums[a] != 0)    swap(nums[a], nums[non_zero_index++]);
        }
    }
};