/*
문제 링크 : https://leetcode.com/problems/permutations-ii/
중복이 있는 배열의 모든 permutation을 구하는 문제다.

recursion을 통해 해결할 수 있다.

먼저, nums내의 값과 갯수를 map으로 만든다. 그런 다음 map의 value값이 0보다 큰 key값들을 permuation에 넣고 빼는 방식으로 모든 permutation을 구할 수 있다.
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> permutation;
        map<int, int> m;
        //nums에 있는 값과 그 값의 갯수를 map의 key value로 구성
        for (int a = 0; a < nums.size(); a++) {
            if (m.find(nums[a]) == m.end())  m[nums[a]] = 0;
            m[nums[a]]++;
        }
        Get_Answer(answer, permutation, m, nums.size());

        return answer;
    }

    void Get_Answer(vector<vector<int>>& answer, vector<int>& permutation, map<int, int>& m, int num) {
        if (num == 0)    answer.push_back(permutation); //permutation이 완성된 경우

        for (map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second != 0) { //value값이 0이 아닌 경우
                permutation.push_back(itr->first);  //permutation의 끝에 포함
                itr->second--;
                Get_Answer(answer, permutation, m, num - 1);    //recursion
                permutation.pop_back(); 
                itr->second++;
            }
        }
    }
};