/*
문제 링크 : https://leetcode.com/problems/search-in-rotated-sorted-array/
Binary Search로 해결할 수 있는 문제다.

정렬된 배열이 rotated 된 결과를 서로 다르게 정렬된 2개의 배열로 생각하였다.

먼저 배열에서 가장 작은 숫자가 위치한 곳을 찾은 다음 해당 지점을 기준으로 좌측 우측을 따로 이진 탐색을 통해 정답을 구하였다.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle, index;
        //가장 작은 숫자가 있는 곳의 index 계산하기
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] > nums[right])  left = middle + 1;
            else    right = middle;
        }
        index = left;
        //index기준 좌측에 대해서 이진 탐색으로 target찾기
        left = 0, right = index - 1;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target)  return middle;
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        //index기준 우측에 대해서 이진 탐색으로 target찾기
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