/*
���� ��ũ : https://leetcode.com/problems/combination-sum-ii/
(leetcode)39�� ������ ���� ����ϰ� recursion���� �ذ��� �� �ִ�.

�ٸ� �־��� candidates�迭�� �ߺ��� ���� �� �ֱ⿡ �ش� �κ��� ó�����ִ� �ڵ�� �����ϸ� �ȴ�.
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combination;

        sort(candidates.begin(), candidates.end()); //candidates�� �ߺ� ó���� ���� ����
        Get_Answer(candidates, answer, combination, target, 0, 1);

        return answer;
    }

    void Get_Answer(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& combination, int remain, int index, int same_num) {
        if (remain == 0) {  //target���� ������ ��� answer�� �߰�
            answer.push_back(combination);
            return;
        }
        if (index >= candidates.size() || remain < candidates[index])  return;  //target�� �޼��� ������ ���

        if (index < candidates.size() - 1 && candidates[index] == candidates[index + 1]) {  //���� index + 1��°�� index��°�� ���� ���ٸ� index + 1��°���� Ž���� �ѱ�
            Get_Answer(candidates, answer, combination, remain, index + 1, same_num + 1);
        }
        else {  //index�� index + 1�� ���� �ٸ��ٴ� ���� index��°�� �ߺ��� ���� ���������� �ǹ�
            for (int a = 1; a <= same_num; a++) {       //index��°�� ���� 1��, 2�� ... same_num���� ���� ��� ���
                combination.push_back(candidates[index]);
                Get_Answer(candidates, answer, combination, remain - (a * candidates[index]), index + 1, 1);
            }
            for (int a = 1; a <= same_num; a++)  combination.pop_back();
            Get_Answer(candidates, answer, combination, remain, index + 1, 1);  //index��°�� ���� �ϳ��� ���� �ʴ� ���
        }
    }
};