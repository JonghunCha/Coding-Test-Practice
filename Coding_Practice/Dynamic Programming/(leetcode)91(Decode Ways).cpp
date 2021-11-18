/*
���� ��ũ : https://leetcode.com/problems/decode-ways/
DP�� �ذ��� �� �ִ� ������.

���ڿ��� �տ������� ������ ���Ǹ� �� �������� decoding���� �� �� ������ ���� �� �ִ��� ����ϸ� �ȴ�.

�Ʒ� �ڵ带 ���� ���� ������ �� �ִ�.
*/
class Solution {
public:
    int numDecodings(string s) {
        int answer = 0, n = s.size(), dp[n];    //dp[n]�� n��° index������ ���ڿ��� decoding�Ǵ� ����� ������ ����
        char prev;  //prev�� ������ ���Դ� ���� ����

        for (int a = 0; a < n; a++)  dp[a] = -1;
        //s.size()�� 1�� ���
        if (s.size() == 1) {    
            if (s[0] == '0') return 0;
            else    return 1;
        }
        //s.size()�� 2�̻��� ���(dp[0]�� dp[1]�� �ʱⰪ�� ��� �� ����)
        if (s[0] == '0') return 0;
        else if (s[0] == '1') { 
            if (s[1] == '0') dp[1] = 1;
            else    dp[1] = 2;
        }
        else if (s[0] == '2') {
            if (s[1] <= '6' && s[1] >= '1') dp[1] = 2;
            else    dp[1] = 1;
        }
        else {
            if (s[1] == '0') return 0;
            dp[1] = 1;
        }
        dp[0] = 1;
        prev = s[1];
        //������ �κ��� dp ���
        for (int a = 2; a < n; a++) {
            if (s[a] == '0') {  //'0'���� �տ��� '1'�Ǵ� '2'�� �־���Ѵ�
                if (prev != '1' && prev != '2')  return 0;
                else    dp[a] = dp[a - 2];
            }
            else { 
                if (prev == '0') dp[a] = dp[a - 1];
                else if (prev == '1')    dp[a] = dp[a - 1] + dp[a - 2];
                else if (prev == '2') {
                    if (s[a] <= '6') dp[a] = dp[a - 1] + dp[a - 2];
                    else    dp[a] = dp[a - 1];
                }
                else    dp[a] = dp[a - 1];
            }
            prev = s[a];
        }

        return dp[n - 1];
    }
};