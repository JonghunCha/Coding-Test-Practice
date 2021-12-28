/*
���� ��ũ : https://leetcode.com/problems/squares-of-a-sorted-array/
Two Pointers�� �ذ��� �� �ִ� ������.

���ĵ� integer �迭�� �־����� �ش� �迭 ����� ���� ���� ������������ ���ĵ� �迭�� ��ȯ�ؾ��Ѵ�.

�켱 ��� �迭 ���ҵ��� �����ϸ� ���� ���� ���� ��ġ�� �˾Ƴ���.

�׷� ���� ���� ���� ���� ��ġ ���ʰ� �������� ���ϸ� �� ���� ���� ret���Ϳ� �־��ִ� ������� �ذ��ϸ� �ȴ�.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int min = 10000000000, min_index, left, right;
        vector<int> ret;
        //�������� ���ϸ� �ּڰ��� ���ÿ� ���
        for (int a = 0; a < nums.size(); a++) {
            nums[a] *= nums[a];
            if (nums[a] < min) {
                min = nums[a];
                min_index = a;
            }
        }
        //�ּڰ��� ret���Ϳ� �־��ְ� left�� right�� min_index ��,��� ����
        ret.emplace_back(nums[min_index]);
        left = min_index - 1;
        right = min_index + 1;
        //left�� right�� �ϳ��� ��ȿ�� index�� ������ �ݺ�
        while (left >= 0 || right < nums.size()) {
            if (left < 0)    ret.emplace_back(nums[right++]);   //min_index ������ ���� ��� ret�� �� ���
            else if (right >= nums.size())   ret.emplace_back(nums[left--]);    //min_index �������� ���� ��� ret�� �� ���
            else {
                if (nums[left] < nums[right])    ret.emplace_back(nums[left--]);
                else    ret.emplace_back(nums[right++]);
            }
        }
        return ret;
    }
};