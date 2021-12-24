/*
���� ��ũ : https://leetcode.com/problems/integer-break/
DP�� �ذ��� �� �ִ� ������.

dp[a]�� n�� a�� ���� ������ �����Ѵٰ� ��������.

�Ʒ� �ڵ带 ���� dp[a]�� ��� ����ϴ��� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int integerBreak(int n) {
        int dp[59], max, temp;
        //dp�ʱ�ȭ
        for (int a = 2; a < 59; a++) dp[a] = -1;
        dp[2] = 1;
        //���� ������ dp �� ���
        for (int a = 3; a <= n; a++) {
            max = 0;
            for (int b = 1; b <= a / 2; b++) {  //(a/2)�� ���ų� ���� �� b�� ����
                temp = b * (a - b); //a�� b�� (a-b) 2���� ������ ����� product ��
                if (temp > max)  max = temp;
                temp = b * dp[a - b];   //a�� b�� dp[a-b] �� 3�� �̻��� ���� ������ ����� product ��
                if (temp > max)  max = temp;
            }
            dp[a] = max;    //�� ����� ���� �� ���� ū ���� dp[a]�� ���� �ȴ�.
        }

        return dp[n];
    }
};