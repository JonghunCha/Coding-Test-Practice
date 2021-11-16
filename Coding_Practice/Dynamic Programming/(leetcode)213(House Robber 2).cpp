/*
문제 링크 : https://leetcode.com/problems/house-robber-ii/
Dynamic Programming으로 해결할 수 있는 문제다.

문제에서 집은 원형으로 배치가 되어 있고, 첫 집은 마지막 집과 이웃이라고 한다.

따라서 전체 문제를 아래와 같은 2개의 문제로 나눌 수 있다.

1. 0번 집부터 시작해서 n-2번 집까지만 고려하는 경우(0번 집과 n-1집은 동시에 도둑질할 수 없다)
2. 1번 집부터 시작해서 n-1번 집까지만 고려하는 경우(위와 마찬가지의 이유)

위 두 경우에 대해 Dynamic Programming의 아이디어를 이용해 각각 정답을 도출하고, 둘 중 더 큰 값을 반환하면 된다.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)  return nums[0];
        if (n == 2)  return max(nums[0], nums[1]);
        return max(Get_Answer(nums, 0, n - 2), Get_Answer(nums, 1, n - 1)); //위 설명의 1번과 2번 경우들 중 큰 값을 반환
    }

    int Get_Answer(vector<int>& nums, int start, int end) {
        int pre1 = 0, pre2 = 0, temp;   //pre1은 현재 index에서 1칸 이전의 집까지만 도둑질 했을 때 최댓값, pre2는 2칸 이전의 집에 대한 최댓값
        for (int a = start; a <= end; a++) {
            temp = max((nums[a] + pre2), pre1);
            pre2 = pre1;
            pre1 = temp;
        }
        return temp;
    }
};