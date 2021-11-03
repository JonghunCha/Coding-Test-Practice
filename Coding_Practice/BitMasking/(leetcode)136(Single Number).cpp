/*
���� ��ũ : https://leetcode.com/problems/single-number/
��Ʈ����ŷ�� ����ϸ� ª�� �ڵ�� �ذ��� �� �ִ�.

��Ʈ �������� XOR�����ڸ� �̿��ϸ� �ȴ�.

�־��� �迭���� �Ȱ��� ���� xor�� ��ġ�� �� 0�� �ȴ�.(A^A = 0)

���� �迭�� ��� ���� xor������ ��ġ�� �ϸ� 2���� �ִ� ���� ��� 0���� ������ ���̰� �ᱹ �ϳ��� �����ϴ� ���� ���� �ȴ�.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = nums[0];
        for (int a = 1; a < nums.size(); a++) {
            answer = answer ^ nums[a];
        }
        return answer;
    }
};