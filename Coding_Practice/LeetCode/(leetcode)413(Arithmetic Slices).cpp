/*
���� ��ũ : https://leetcode.com/problems/arithmetic-slices/
dp�� �ذ��� �� �ִ� ������.

dp[n]�� n��° index���� �������� ���� arithmetic slice�� ������ �����Ѵ�.

���� dp[0]�� 2��� 0��°���� 3��°������ ���̰� ���� ������ �ǹ��Ѵ�. (arithmetic slice : (0, 1, 2), (0, 1, 2, 3) 2����)

�׷��ٸ� dp[1]�� �ڵ������� dp[0]���� 1���� 1�̵ȴ�.

�̷��� ���̵��� 0��°���� n-3��°������ dp���� ���� �� ��ü�� �����ָ� �ȴ�. �Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;  //ũ�Ⱑ 3���� ���� ���� �׻� 0 ��ȯ

        int answer = 0, n = nums.size(), index, diff, dp[nums.size() - 2];

        for (int a = 0; a < n - 2; a++)    dp[a] = -1;  

        for (int a = 0; a < n - 2; a++) { 
            if (a > 0 && dp[a - 1] > 0) {   //���� a-1��° dp�� 0���� ũ�ٸ� a��° dp�� a-1��°�� ������ 1���⸸ �ϸ��
                dp[a] = dp[a - 1] - 1;
                continue;
            }
            
            diff = nums[a + 1] - nums[a];   //���� diff�� ����
            index = a + 2; 
            while (index < n) { //diff���� �ٸ� ���� ���� ������ �ݺ�
                if (nums[index] - nums[index - 1] != diff)  break;
                index++;
            }
            dp[a] = index - a - 2;  
        }

        for (int a = 0; a < n - 2; a++)    answer += dp[a];

        return answer;
    }
};