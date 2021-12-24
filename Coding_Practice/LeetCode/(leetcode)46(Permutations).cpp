/*
���� ��ũ : https://leetcode.com/problems/permutations/
��� �Լ��� �̿��� DFS�� �ذ��� �� �ִ� ������.

�� ��Ϳ��� �־��� nums���� ���õ��� ���� ���� �����ϰ� �ٽ� ��� �Լ��� ȣ�������ν� ���õ��� ���� ���� �� �ϳ��� �����ϴ� ���� �ݺ��Ѵ�.
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> permutation;    //permutation�� �����ϴ� ����
        vector<int> selected;       //������ �� ������ �ƴ����� ��Ÿ��
        for (int a = 0; a < nums.size(); a++)    selected.push_back(0);
        Get_Permutations(nums, answer, permutation, selected);
        return answer;
    }

    void Get_Permutations(vector<int>& nums, vector<vector<int>>& answer, vector<int>& permutation, vector<int>& selected) {
        if (nums.size() == permutation.size()) {    //��� ���ڰ� ���õǾ����� answer�� �߰�
            answer.push_back(permutation);
            return;
        }
        //���õ��� ���� ���� ���� ��� �Լ� ȣ��
        for (int a = 0; a < nums.size(); a++) {
            if (selected[a] == 0) {
                permutation.push_back(nums[a]);
                selected[a] = 1;
                Get_Permutations(nums, answer, permutation, selected);
                selected[a] = 0;
                permutation.pop_back();
            }
        }
        return;
    }
};