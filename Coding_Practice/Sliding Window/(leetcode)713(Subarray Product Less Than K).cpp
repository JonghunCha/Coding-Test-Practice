/*
���� ��ũ : https://leetcode.com/problems/subarray-product-less-than-k/
Sliding Window�� �ذ��� �� �ִ� ������.

�Ʒ� �ڵ带 ���� �ݹ� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int answer = 0, product = 1, left = 0;  //left�� ���� Ž������ subarray���� ���� ������ index�� �ǹ�

        if (k <= 1)  return 0;
        for (int a = 0; a < nums.size(); a++) {
            product *= nums[a];
            while (product >= k) {  //���ο� a��° index�� ���� ������ �� k�� �Ѵ´ٸ� �Ʒ� ������ �ݺ��ϸ� answer�� ����
                product /= nums[left];
                answer += a - left; //a��° index�� ���� �������� ���� left�κ��� �����Ͽ� a-1��° ���� ������ ��� k�� ���� �ʾҴ�
                left++;
            }
        }
        if (nums.size() > left) {   //���� �ݺ����� ���� ���� ��, ���� answer�� �߰����� ���� ������� �߰�
            for (int a = 1; a <= nums.size() - left; a++) answer += a;
        }

        return answer;
    }
};