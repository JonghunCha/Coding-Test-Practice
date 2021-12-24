/*
문제 링크 : https://leetcode.com/problems/combinations/
재귀 함수를 이용한 DFS로 해결할 수 있다.

1~n까지의 정수 중 k개를 고르는 모든 방법을 알아내는 문제다.

k개를 고르는 재귀 함수를 구현하면 쉽게 풀 수 있다.
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
        //k개의 수를 다 선택한 경우 answer에 추가
        if (k == combination.size()) {
            answer.push_back(combination);
            return;
        }
        //아직 k개를 고르지 못했지만 더 이상의 후보가 없는 경우 종료
        if (index >= n)  return;
        //index+1을 선택하는 경우
        combination.push_back(index + 1);
        Get_Combinations(answer, combination, n, k, index + 1);
        //index+1을 선택하지 않는 경우
        combination.pop_back();
        Get_Combinations(answer, combination, n, k, index + 1);
        return;
    }
};