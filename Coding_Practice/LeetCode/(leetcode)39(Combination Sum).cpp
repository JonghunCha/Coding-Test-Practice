/*
문제 링크 : https://leetcode.com/problems/combination-sum/
recursion을 통한 완전탐색으로 해결할 수 있다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combination;

        sort(candidates.begin(), candidates.end()); //작은 수부터 접근하기 위해 sorting
        Get_Answer(candidates, answer, combination, target, 0);

        return answer;
    }
    
    void Get_Answer(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& combination, int remain, int index) {
        if (remain == 0) {  //combination내부의 합이 target이 되었을 때
            answer.push_back(combination);
            return;
        }
        if (remain < candidates[index])    return;  //target을 만들 방법이 없는 경우
        
        for (int a = index; a < candidates.size(); a++) {   //index번째의 수부터 살피며 remain보다 작으면 탐색 진행
            if (candidates[a] <= remain) {
                combination.push_back(candidates[a]);
                Get_Answer(candidates, answer, combination, remain - candidates[a], a);
                combination.pop_back();
            }
        }
    }
};