/*
���� ��ũ : https://leetcode.com/problems/coin-change/
DP�� �ذ��� �� �ִ� ������.

dp[a]�� amount�� a�� �� ������ �ǹ��Ѵ�.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), dp[10001];
        //coins���� �� dp �ʱ�ȭ
        sort(coins.begin(), coins.end());
        for (int a = 0; a <= amount; a++)    dp[a] = 0;

        return DP(coins, amount, dp);
    }

    int DP(vector<int>& coins, int amount, int dp[10001]) {
        int n = coins.size(), min = 20000, temp;
        //�̹� ����� ��� �ٷ� ��ȯ
        if (dp[amount] != 0)    return dp[amount];
      
        if (amount == 0) return 0;  //amount�� 0�� ���� ������ �� �ʿ䰡 ����
        else if (amount < coins[0]) {   //���� amount�� ���� ���� ���κ��� ũ�Ⱑ �۴ٸ� �׻� -1��ȯ
            dp[amount] = -1;
            return -1;
        }
        else {  //��� 1�� �̻��� ������ amount���� �۰ų� ���� ���
            for (int a = 0; a < n; a++) {
                if (coins[a] <= amount) {
                    temp = DP(coins, amount - coins[a], dp);
                    if (temp != -1) {   //temp�� -1�� ��츦 �����ϰ� min�� ����
                        temp++;
                        if (temp < min)  min = temp;
                    }
                }
                else    break;
            }

            if (min == 20000)    dp[amount] = -1;   //min�� 20000���� �� �ٲ� ���� �ش� amount�� ������ �� ���ٴ� �ǹ�
            else    dp[amount] = min;
            return dp[amount];
        }
    }
};