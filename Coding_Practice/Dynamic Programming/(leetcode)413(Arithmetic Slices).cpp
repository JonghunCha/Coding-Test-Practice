/*
문제 링크 : https://leetcode.com/problems/arithmetic-slices/
dp로 해결할 수 있는 문제다.

dp[n]은 n번째 index부터 시작했을 때의 arithmetic slice의 갯수를 저장한다.

만약 dp[0]이 2라면 0번째부터 3번째까지의 차이가 서로 같음을 의미한다. (arithmetic slice : (0, 1, 2), (0, 1, 2, 3) 2가지)

그렇다면 dp[1]은 자동적으로 dp[0]보다 1작은 1이된다.

이러한 아이디어로 0번째부터 n-3번째까지의 dp값을 구한 뒤 전체를 더해주면 된다. 아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;  //크기가 3보다 작은 경우는 항상 0 반환

        int answer = 0, n = nums.size(), index, diff, dp[nums.size() - 2];

        for (int a = 0; a < n - 2; a++)    dp[a] = -1;  

        for (int a = 0; a < n - 2; a++) { 
            if (a > 0 && dp[a - 1] > 0) {   //만약 a-1번째 dp가 0보다 크다면 a번째 dp는 a-1번째의 값에서 1빼기만 하면됨
                dp[a] = dp[a - 1] - 1;
                continue;
            }
            
            diff = nums[a + 1] - nums[a];   //기준 diff값 지정
            index = a + 2; 
            while (index < n) { //diff값과 다른 값이 나올 때까지 반복
                if (nums[index] - nums[index - 1] != diff)  break;
                index++;
            }
            dp[a] = index - a - 2;  
        }

        for (int a = 0; a < n - 2; a++)    answer += dp[a];

        return answer;
    }
};