/*
���� ��ũ : https://leetcode.com/problems/combination-sum/
recursion�� ���� ����Ž������ �ذ��� �� �ִ�.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combination;

        sort(candidates.begin(), candidates.end()); //���� ������ �����ϱ� ���� sorting
        Get_Answer(candidates, answer, combination, target, 0);

        return answer;
    }
    
    void Get_Answer(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& combination, int remain, int index) {
        if (remain == 0) {  //combination������ ���� target�� �Ǿ��� ��
            answer.push_back(combination);
            return;
        }
        if (remain < candidates[index])    return;  //target�� ���� ����� ���� ���
        
        for (int a = index; a < candidates.size(); a++) {   //index��°�� ������ ���Ǹ� remain���� ������ Ž�� ����
            if (candidates[a] <= remain) {
                combination.push_back(candidates[a]);
                Get_Answer(candidates, answer, combination, remain - candidates[a], a);
                combination.pop_back();
            }
        }
    }
};