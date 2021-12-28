/*
���� ��ũ : https://leetcode.com/problems/combinations/
��� �Լ��� �̿��� DFS�� �ذ��� �� �ִ�.

1~n������ ���� �� k���� ���� ��� ����� �˾Ƴ��� ������.

k���� ���� ��� �Լ��� �����ϸ� ���� Ǯ �� �ִ�.
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> combination;
        Get_Combinations(answer, combination, n, k, 0);
        return answer;
    }

    void Get_Combinations(vector<vector<int>>& answer, vector<int>& combination, int n, int k, int index) {
        //k���� ���� �� ������ ��� answer�� �߰�
        if (k == combination.size()) {
            answer.push_back(combination);
            return;
        }
        //���� k���� ���� �������� �� �̻��� �ĺ��� ���� ��� ����
        if (index >= n)  return;
        //index+1�� �����ϴ� ���
        combination.push_back(index + 1);
        Get_Combinations(answer, combination, n, k, index + 1);
        //index+1�� �������� �ʴ� ���
        combination.pop_back();
        Get_Combinations(answer, combination, n, k, index + 1);
        return;
    }
};