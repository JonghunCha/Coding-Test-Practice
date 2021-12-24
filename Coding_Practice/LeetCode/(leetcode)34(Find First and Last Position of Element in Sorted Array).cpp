/*
���� ��ũ : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Binary Search�� �ذ��� �� �ִ� ������.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_idx = -1, last_idx = -1;  //���ϰ����ϴ� ó���� ���� �ε���(target�� ���� ��츦 ���� -1�� �ʱ�ȭ �Ѵ�)
        int left = 0, right = nums.size() - 1, middle;
        vector<int> answer;
        //first_idxã�� ���� Ž��
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {   //target�� �߰��� ��� �� �տ� target�� �ִ��� ã�´�.
                first_idx = middle;
                right = middle - 1;
            }
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        left = 0, right = nums.size() - 1;
        //last_idxã�� ���� Ž��
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {   //target�� �߰��� ��� �� �ڿ� target�� �ִ��� ã�´�.
                last_idx = middle;
                left = middle + 1;
            }
            else if (nums[middle] < target)  left = middle + 1;
            else    right = middle - 1;
        }
        answer.push_back(first_idx);
        answer.push_back(last_idx);
        return answer;
    }
};