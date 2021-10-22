/*
���� ��ũ : https://leetcode.com/problems/search-insert-position/
���� Ž������ �ذ��� �� �ִ� ������.

���� Ž������ target�� ã���� middle�� �ٷ� ��ȯ�Ѵ�.

while�� ����� �� ���� ��ã���� target�� �迭�� ���� ���̰� �� ������ begin���� target�� ��ġ�ؾ� �� index�̴�.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, middle;
        while (begin <= end) {
            middle = (begin + end) / 2;
            if (nums[middle] == target)  return middle;
            else if (nums[middle] < target)  begin = ++middle;
            else    end = --middle;
        }
        return begin;
    }
};