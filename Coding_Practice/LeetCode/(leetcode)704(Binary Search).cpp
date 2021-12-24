/*
문제 링크 : https://leetcode.com/problems/binary-search/
Binary Search의 기본 원리만 알면 쉽게 해결할 수 있는 문제다.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, middle;
        while (begin <= end) {
            middle = (begin + end) / 2;
            if (nums[middle] == target)  return middle;
            else if (nums[middle] < target)  begin = middle + 1;
            else    end = middle - 1;
        }
        return -1;
    }
};