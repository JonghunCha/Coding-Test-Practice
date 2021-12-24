/*
문제 링크 : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
rotated된 배열에서 가장 작은 값을 찾는 이진 탐색 문제다.

(leetcode)33번 문제에서 사용한 방법 그대로 구현하면 된다.
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