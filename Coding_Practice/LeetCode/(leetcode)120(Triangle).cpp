/*
���� ��ũ : https://leetcode.com/problems/triangle/
Dynamic Programming���� �ذ��� �� �ִ� ������.

���� ���������� �Ʒ��� ���ʿ������� ���������� Ž���ϸ� �ش� ��忡 �����ϱ���� �ּڰ��� ����ϸ� �ȴ�.

�Է� �����͸� Ʈ����� ��������.

�켱 �� �������� ���� ���ʿ� �ִ� ���� ���� ������ ���� ���� ��忡���ۿ� ������� �ʴ´�. �ݴ�� ���� ������ ��嵵 ���������̴�.
�߾��� ������ ���� ������ 2�� ��忡�� ����� �� �����Ƿ� 2���� ����� path sum�� ���� ���� �����ϸ� �ȴ�.

�Ʒ� �ڵ带 ���� �ݹ� ������ ���̴�.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1)    return triangle[0][0]; //������ 1�ΰ�� ó��
        int dp[200][200], answer = 10000000;
        dp[0][0] = triangle[0][0];
        for (int a = 1; a < triangle.size(); a++) {
            for (int b = 0; b <= a; b++) {
                if (b == 0)  dp[a][b] = dp[a - 1][b] + triangle[a][b];  //���� ���� ����� ���
                else if (b == a) dp[a][b] = dp[a - 1][b - 1] + triangle[a][b];  //���� ������ ����� ���
                else    dp[a][b] = min(dp[a - 1][b - 1], dp[a - 1][b]) + triangle[a][b];    //�߾ӿ� ��ġ�� ����� ���
            }
        }
        for (int a = 0; a < triangle.size(); a++) {
            if (dp[triangle.size() - 1][a] < answer) answer = dp[triangle.size() - 1][a];
        }
        return answer;
    }
};