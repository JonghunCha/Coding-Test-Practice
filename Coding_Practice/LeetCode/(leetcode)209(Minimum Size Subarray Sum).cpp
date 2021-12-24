/*
문제 링크 : https://leetcode.com/problems/minimum-size-subarray-sum/
Sliding Window로 해결할 수 있는 문제다.

우선 처음부터 시작하여 target을 넘는 지점을 찾는다.

해당 지점부터 최소의 길이를 구하기 위해 가장 왼쪽의 수를 뺏을 때도 target을 넘는지 확인한다.

만약 가장 왼쪽의 수를 빼도 target을 넘는다면 해당 수를 빼고 다음 탐색을 진행한다.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = 1000000, left = 0, sum = 0;
        
        for (int a = 0; a < nums.size(); a++) {
            sum += nums[a]; //a번째 수를 더한다
            if (sum >= target) {    //만약 합이 target값을 넘겼다면
                while (left >= 0) { 
                    if (sum - nums[left] >= target) {   //가장 왼쪽의 수를 빼도 target값을 넘긴다면 빼버린다
                        sum -= nums[left++];
                    }
                    else    break;
                }
                if (a - left + 1 < answer)   answer = a - left + 1; //가장 짧은 길이를 갱신
            }
        }

        if (answer == 1000000)   return 0;
        return answer;
    }
};