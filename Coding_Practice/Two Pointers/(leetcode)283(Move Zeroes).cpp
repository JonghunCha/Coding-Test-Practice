/*
문제 링크 : https://leetcode.com/problems/move-zeroes/
Two Pointers로 간단하게 해결할 수 있다.

첫 번째 포인터는 nums를 시작부터 끝까지 탐색하는 역할을 하고 두 번째 포인터는 0이 아닌 숫자가 들어갈 위치의 index를 가르킨다.

첫 번째 포인터가 0이 아닌 숫자를 발견할 때마다 두 번째 포인터가 가르키는 위치와 swap을 하고 두 번째 포인터는 다음 index를 가르키도록 하면 된다.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero_index = 0;
        for (int a = 0; a < nums.size(); a++) {
            if (nums[a] != 0)    swap(nums[a], nums[non_zero_index++]);
        }
    }
};