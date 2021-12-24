/*
문제 링크 : https://leetcode.com/problems/triangle/
Dynamic Programming으로 해결할 수 있는 문제다.

가장 위에서부터 아래로 왼쪽에서부터 오른쪽으로 탐색하며 해당 노드에 도착하기까지 최솟값을 계산하면 된다.

입력 데이터를 트리라고 생각하자.

우선 각 레벨에서 가장 왼쪽에 있는 노드는 상위 레벨의 가장 왼쪽 노드에서밖에 연결되지 않는다. 반대로 가장 오른쪽 노드도 마찬가지이다.
중앙의 노드들은 상위 레벨의 2개 노드에서 연결될 수 있으므로 2개의 노드중 path sum이 작은 것을 선택하면 된다.

아래 코드를 보면 금방 이해할 것이다.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1)    return triangle[0][0]; //레벨이 1인경우 처리
        int dp[200][200], answer = 10000000;
        dp[0][0] = triangle[0][0];
        for (int a = 1; a < triangle.size(); a++) {
            for (int b = 0; b <= a; b++) {
                if (b == 0)  dp[a][b] = dp[a - 1][b] + triangle[a][b];  //가장 왼쪽 노드인 경우
                else if (b == a) dp[a][b] = dp[a - 1][b - 1] + triangle[a][b];  //가장 오른쪽 노드인 경우
                else    dp[a][b] = min(dp[a - 1][b - 1], dp[a - 1][b]) + triangle[a][b];    //중앙에 위치한 노드의 경우
            }
        }
        for (int a = 0; a < triangle.size(); a++) {
            if (dp[triangle.size() - 1][a] < answer) answer = dp[triangle.size() - 1][a];
        }
        return answer;
    }
};