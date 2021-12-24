/*
���� ��ũ : https://leetcode.com/problems/search-in-rotated-sorted-array/
Binary Search�� �ذ��� �� �ִ� ������.

���ĵ� �迭�� rotated �� ����� ���� �ٸ��� ���ĵ� 2���� �迭�� �����Ͽ���.

���� �迭���� ���� ���� ���ڰ� ��ġ�� ���� ã�� ���� �ش� ������ �������� ���� ������ ���� ���� Ž���� ���� ������ ���Ͽ���.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle, index;
        //���� ���� ���ڰ� �ִ� ���� index ����ϱ�
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] > nums[right])  left = middle + 1;
            else    right = middle;
        }
        index = left;
        //index���� ������ ���ؼ� ���� Ž������ targetã��
        left = 0, right = index - 1;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target)  return middle;
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        //index���� ������ ���ؼ� ���� Ž������ targetã��
        left = index, right = nums.size() - 1;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target)  return middle;
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        return -1;
    }
};