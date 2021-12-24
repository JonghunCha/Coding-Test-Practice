/*
���� ��ũ : https://leetcode.com/problems/minimum-size-subarray-sum/
Sliding Window�� �ذ��� �� �ִ� ������.

�켱 ó������ �����Ͽ� target�� �Ѵ� ������ ã�´�.

�ش� �������� �ּ��� ���̸� ���ϱ� ���� ���� ������ ���� ���� ���� target�� �Ѵ��� Ȯ���Ѵ�.

���� ���� ������ ���� ���� target�� �Ѵ´ٸ� �ش� ���� ���� ���� Ž���� �����Ѵ�.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = 1000000, left = 0, sum = 0;
        
        for (int a = 0; a < nums.size(); a++) {
            sum += nums[a]; //a��° ���� ���Ѵ�
            if (sum >= target) {    //���� ���� target���� �Ѱ�ٸ�
                while (left >= 0) { 
                    if (sum - nums[left] >= target) {   //���� ������ ���� ���� target���� �ѱ�ٸ� ��������
                        sum -= nums[left++];
                    }
                    else    break;
                }
                if (a - left + 1 < answer)   answer = a - left + 1; //���� ª�� ���̸� ����
            }
        }

        if (answer == 1000000)   return 0;
        return answer;
    }
};