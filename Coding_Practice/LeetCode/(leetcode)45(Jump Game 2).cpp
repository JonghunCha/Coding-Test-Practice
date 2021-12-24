/*
문제 링크 : https://leetcode.com/problems/jump-game-ii/
DP로 해결할 수 있는 문제다.

answer[n]은 n번째 위치까지 몇 번의 점프로 도달할 수 있는지를 저장한다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), answer[n], curr = 0;   //curr은 현재 몇 번째 index까지 최단 점프 횟수를 구했는지를 의미

        for (int a = 0; a < n; a++)  answer[a] = -1;
        answer[0] = 0; 
        for (int a = 0; a < n; a++) {
            for (int b = curr - a + 1; b <= nums[a]; b++) { //curr다음부터 a에서 점프할수 있는 최대거리까지 반복
                if (a + b < n && answer[a + b] == -1) {
                    answer[a + b] = answer[a] + 1;  
                    curr = a + b;
                }
                if (a + b == n - 1)  return answer[n - 1];
            }
        }

        return answer[n - 1];
    }
};