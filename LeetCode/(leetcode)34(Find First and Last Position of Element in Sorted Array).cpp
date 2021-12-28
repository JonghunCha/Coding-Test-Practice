/*
문제 링크 : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Binary Search로 해결할 수 있는 문제다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_idx = -1, last_idx = -1;  //구하고자하는 처음과 끝의 인덱스(target이 없는 경우를 위해 -1로 초기화 한다)
        int left = 0, right = nums.size() - 1, middle;
        vector<int> answer;
        //first_idx찾는 이진 탐색
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {   //target을 발견한 경우 더 앞에 target이 있는지 찾는다.
                first_idx = middle;
                right = middle - 1;
            }
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        left = 0, right = nums.size() - 1;
        //last_idx찾는 이진 탐색
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {   //target을 발견한 경우 더 뒤에 target이 있는지 찾는다.
                last_idx = middle;
                left = middle + 1;
            }
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        answer.push_back(first_idx);
        answer.push_back(last_idx);
        return answer;
    }
};