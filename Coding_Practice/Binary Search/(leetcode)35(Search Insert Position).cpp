/*
문제 링크 : https://leetcode.com/problems/search-insert-position/
이진 탐색으로 해결할 수 있는 문제다.

이진 탐색으로 target을 찾으면 middle을 바로 반환한다.

while이 종료될 때 까지 못찾으면 target은 배열에 없는 것이고 그 시점의 begin값이 target이 위치해야 할 index이다.
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