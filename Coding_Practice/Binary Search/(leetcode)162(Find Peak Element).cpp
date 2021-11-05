/*
문제 링크 : https://leetcode.com/problems/find-peak-element/
어떤 구간에서 가장 큰 수는 반드시 Peak라는 점을 이용하면 된다.

이진 탐색을 통해 middle지역과 middle + 1지역을 비교한다.

만약 middle + 1 지역이 더 큰 수라면 오른쪽 부분을 탐색하고, 반대의 경우 왼쪽 부분을 탐색한다.
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