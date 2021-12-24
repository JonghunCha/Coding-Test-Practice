/*
문제 링크 : https://leetcode.com/problems/subsets/
완전 탐색을 통해 해결할 수 있다.

DFS기반으로 구현하되, 탐색 과정에서 생기는 subset또한 문제에서 구하라고 한 정답에 포함되기에 DFS탐색 과정마다 정답에 subset을 넣어주면 된다.
(일종의 Backtracking이랑 비슷한 느낌)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer; //정답 벡터
        vector<int> subset; //정답에 넣을 부분 집합

        Get_Answer(nums, answer, subset, 0);
        return answer;
    }

    void Get_Answer(vector<int>& nums, vector<vector<int>>& answer, vector<int>& subset, int index) {
        answer.push_back(subset);   //현재까지 만들어진 subset을 정답에 넣는다

        for (int a = index; a < nums.size(); a++) { //index번째 수를 subset에 넣는 경우와 그렇지 않은 경우로 나누어서 탐색 진행
            subset.push_back(nums[a]);
            Get_Answer(nums, answer, subset, a + 1);
            subset.pop_back();
        }
    }
};