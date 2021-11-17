/*
���� ��ũ : https://leetcode.com/problems/jump-game-ii/
DP�� �ذ��� �� �ִ� ������.

answer[n]�� n��° ��ġ���� �� ���� ������ ������ �� �ִ����� �����Ѵ�.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), answer[n], curr = 0;   //curr�� ���� �� ��° index���� �ִ� ���� Ƚ���� ���ߴ����� �ǹ�

        for (int a = 0; a < n; a++)  answer[a] = -1;
        answer[0] = 0; 
        for (int a = 0; a < n; a++) {
            for (int b = curr - a + 1; b <= nums[a]; b++) { //curr�������� a���� �����Ҽ� �ִ� �ִ�Ÿ����� �ݺ�
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