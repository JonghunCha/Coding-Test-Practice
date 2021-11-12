/*
문제 링크 : https://leetcode.com/problems/combination-sum-ii/
(leetcode)39번 문제와 거의 흡사하게 recursion으로 해결할 수 있다.

다만 주어진 candidates배열에 중복이 있을 수 있기에 해당 부분을 처리해주는 코드로 수정하면 된다.
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combination;

        sort(candidates.begin(), candidates.end()); //candidates의 중복 처리를 위해 정렬
        Get_Answer(candidates, answer, combination, target, 0, 1);

        return answer;
    }

    void Get_Answer(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& combination, int remain, int index, int same_num) {
        if (remain == 0) {  //target값에 도달한 경우 answer에 추가
            answer.push_back(combination);
            return;
        }
        if (index >= candidates.size() || remain < candidates[index])  return;  //target값 달성에 실패한 경우

        if (index < candidates.size() - 1 && candidates[index] == candidates[index + 1]) {  //만약 index + 1번째와 index번째의 수가 같다면 index + 1번째에게 탐색을 넘김
            Get_Answer(candidates, answer, combination, remain, index + 1, same_num + 1);
        }
        else {  //index와 index + 1의 수가 다르다는 것은 index번째가 중복된 수의 마지막임을 의미
            for (int a = 1; a <= same_num; a++) {       //index번째의 수를 1개, 2개 ... same_num개를 쓰는 경우 고려
                combination.push_back(candidates[index]);
                Get_Answer(candidates, answer, combination, remain - (a * candidates[index]), index + 1, 1);
            }
            for (int a = 1; a <= same_num; a++)  combination.pop_back();
            Get_Answer(candidates, answer, combination, remain, index + 1, 1);  //index번째의 수를 하나도 쓰지 않는 경우
        }
    }
};