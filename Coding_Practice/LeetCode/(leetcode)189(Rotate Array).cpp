/*
���� ��ũ : https://leetcode.com/problems/rotate-array/
leetcode�󿡼� Two Pointer ������ �з��Ǿ� ������ Two Pointer�� �ٽ��̶�⺸�� �������⵵�� �ٷ�� ������ �����Ѵ�

���� ��ü�� ���������� ���� ����� ���� space complexity�� �޶�����.

���� 2���� �ַ���� �����ϰ� ���� ���ϵ��� �ϰڴ�.

1�� ����� �������̰� ���������� nums�� ũ�⸸ŭ�� �޸� ������ �� �ʿ�� �Ѵ�.
���� nums�� ũ�Ⱑ �ſ� ũ�ٸ� ���� ȿ������ �������� �ȴ�.

2�� ����� �ڵ� ��ü�� ���� �� ������ 1�� �濡 ���� �ξ� ���� �޸� ������ �ʿ�� �Ѵ�.(nums�� ����� ũ�ٴ� ���� �Ͽ�)
1�������� nums�� ũ�⸸ŭ �߰� ������ ����Ͽ�����, 2�� ��������� int�� ���� 6������ �߰��� ����Ѵ�.

�� �� ����� �ܿ��� ������� �ø� ���� ������� ����.(������ũ�� Discuss����)
*/

// 1. nums�� ���纻�� ����� �̵��� �Ѵ�. (Time Complexity : O(N), Space Complexity : O(N))
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy;
        int len = nums.size();
        for (int a = 0; a < len; a++)    copy.emplace_back(nums[a]);
        for (int a = 0; a < len; a++)    nums[(a + k) % len] = copy[a];
    }
};

// 2. �ϳ��� ���Һ��� ������ ȸ���� �ϰ� �� ���� ����� ȸ���� ��ġ�� �ִ� ���Ұ� �ǵ����Ѵ�. (Time Complexity : O(N), Space Complexity : O(1))
// ���� ��� nums�� ũ�Ⱑ 8�̰� k�� 3�̶�� (0��ȸ��->3��ȸ��->6��ȸ��->1��ȸ��->4��ȸ��->7��ȸ��->2��ȸ��->5��ȸ��)���� �ȴ�.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotate_count = 0, len = nums.size(), start_index = 0, curr_index = 0, number = nums[0], temp;
        while (rotate_count < len) {
            do {
                temp = nums[(curr_index + k) % len];
                nums[(curr_index + k) % len] = number;
                number = temp;
                curr_index = (curr_index + k) % len;
                rotate_count++;
            } while (curr_index != start_index);
            //nums�� ũ�Ⱑ 4�̰� k�� 2�� ���(0��ȸ��->2��ȸ��->0��ȸ��) 1���� 3���� ȸ�� ��Ű�� ����ä 0���� 2���� �ݺ��� �� �ִ�.
            //���� curr_index�� start_index�� ���� ��� do while�� ���߰� start_index�� 1 �÷� ���ο� do while�� ������ �Ѵ�.
            start_index++;
            curr_index = start_index;
            number = nums[curr_index];
        }
    }
};