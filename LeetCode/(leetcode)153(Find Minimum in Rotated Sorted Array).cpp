/*
���� ��ũ : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
rotated�� �迭���� ���� ���� ���� ã�� ���� Ž�� ������.

(leetcode)33�� �������� ����� ��� �״�� �����ϸ� �ȴ�.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle;
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] > nums[right])  left = middle + 1;
            else right = middle;
        }
        return nums[left];
    }
};