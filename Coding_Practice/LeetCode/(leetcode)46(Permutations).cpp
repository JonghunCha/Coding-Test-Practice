/*
문제 링크 : https://leetcode.com/problems/permutations/
재귀 함수를 이용한 DFS로 해결할 수 있는 문제다.

각 재귀에서 주어진 nums에서 선택되지 않은 수를 선택하고 다시 재귀 함수를 호출함으로써 선택되지 않은 수들 중 하나를 선택하는 것을 반복한다.
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> permutation;    //permutation을 저장하는 변수
        vector<int> selected;       //선택이 된 수인지 아닌지를 나타냄
        for (int a = 0; a < nums.size(); a++)    selected.push_back(0);
        Get_Permutations(nums, answer, permutation, selected);
        return answer;
    }

    void Get_Permutations(vector<int>& nums, vector<vector<int>>& answer, vector<int>& permutation, vector<int>& selected) {
        if (nums.size() == permutation.size()) {    //모든 숫자가 선택되었으면 answer에 추가
            answer.push_back(permutation);
            return;
        }
        //선택되지 않은 수를 고르고 재귀 함수 호출
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