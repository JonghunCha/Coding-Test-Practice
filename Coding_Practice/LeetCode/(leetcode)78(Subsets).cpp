/*
���� ��ũ : https://leetcode.com/problems/subsets/
���� Ž���� ���� �ذ��� �� �ִ�.

DFS������� �����ϵ�, Ž�� �������� ����� subset���� �������� ���϶�� �� ���信 ���ԵǱ⿡ DFSŽ�� �������� ���信 subset�� �־��ָ� �ȴ�.
(������ Backtracking�̶� ����� ����)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer; //���� ����
        vector<int> subset; //���信 ���� �κ� ����

        Get_Answer(nums, answer, subset, 0);
        return answer;
    }

    void Get_Answer(vector<int>& nums, vector<vector<int>>& answer, vector<int>& subset, int index) {
        answer.push_back(subset);   //������� ������� subset�� ���信 �ִ´�

        for (int a = index; a < nums.size(); a++) { //index��° ���� subset�� �ִ� ���� �׷��� ���� ���� ����� Ž�� ����
            subset.push_back(nums[a]);
            Get_Answer(nums, answer, subset, a + 1);
            subset.pop_back();
        }
    }
};