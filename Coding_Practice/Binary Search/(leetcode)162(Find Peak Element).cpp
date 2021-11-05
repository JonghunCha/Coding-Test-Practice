/*
���� ��ũ : https://leetcode.com/problems/find-peak-element/
� �������� ���� ū ���� �ݵ�� Peak��� ���� �̿��ϸ� �ȴ�.

���� Ž���� ���� middle������ middle + 1������ ���Ѵ�.

���� middle + 1 ������ �� ū ����� ������ �κ��� Ž���ϰ�, �ݴ��� ��� ���� �κ��� Ž���Ѵ�.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle;
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] < nums[middle + 1]) left = middle + 1;
            else    right = middle;
        }
        return left;
    }
};