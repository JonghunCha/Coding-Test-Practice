/*
문제 링크 : https://leetcode.com/problems/house-robber/
Dynamic Programming으로 해결할 수 있는 문제다.

집이 n개 있다고 가정하자.

그럼 우리는 n번째 집을 터는 경우와 그렇지 않은 경우 중에서 더 많은 이득을 얻을 수 있는 것을 선택하면 된다.

즉 Answer(N) = max(Answer(N-2) + nums[N], Answer(N-1))이라는 점화식이 성립된다.

아래 코드는 그것을 구현한 것이다.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];    //전체 집의 갯수가 1개이면 그 값을 반환
        int dp[100];    //dp[n]은 n번째 집까지 도둑질한다고 했을 때의 정답 값
        for (int a = 0; a < 100; a++)    dp[a] = -1;
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);
        return DP(nums, dp, nums.size() - 1);
    }

    int DP(vector<int>& nums, int dp[100], int index) {
        if (dp[index] != -1) return dp[index];  //이미 계산된 구역이면 바로 반환
        dp[index] = max(DP(nums, dp, index - 2) + nums[index], DP(nums, dp, index - 1));    //위에서 언급한 점화식
        return dp[index];
    }
};