/*
���� ��ũ : https://leetcode.com/problems/house-robber-ii/
Dynamic Programming���� �ذ��� �� �ִ� ������.

�������� ���� �������� ��ġ�� �Ǿ� �ְ�, ù ���� ������ ���� �̿��̶�� �Ѵ�.

���� ��ü ������ �Ʒ��� ���� 2���� ������ ���� �� �ִ�.

1. 0�� ������ �����ؼ� n-2�� �������� ����ϴ� ���(0�� ���� n-1���� ���ÿ� �������� �� ����)
2. 1�� ������ �����ؼ� n-1�� �������� ����ϴ� ���(���� ���������� ����)

�� �� ��쿡 ���� Dynamic Programming�� ���̵� �̿��� ���� ������ �����ϰ�, �� �� �� ū ���� ��ȯ�ϸ� �ȴ�.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)  return nums[0];
        if (n == 2)  return max(nums[0], nums[1]);
        return max(Get_Answer(nums, 0, n - 2), Get_Answer(nums, 1, n - 1)); //�� ������ 1���� 2�� ���� �� ū ���� ��ȯ
    }

    int Get_Answer(vector<int>& nums, int start, int end) {
        int pre1 = 0, pre2 = 0, temp;   //pre1�� ���� index���� 1ĭ ������ �������� ������ ���� �� �ִ�, pre2�� 2ĭ ������ ���� ���� �ִ�
        for (int a = start; a <= end; a++) {
            temp = max((nums[a] + pre2), pre1);
            pre2 = pre1;
            pre1 = temp;
        }
        return temp;
    }
};