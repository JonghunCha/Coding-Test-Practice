/*
문제 링크 : https://leetcode.com/problems/subsets-ii/
(leetcode)78번 문제와 거의 흡사하지만 초기 배열에 중복 요소가 있을 수 있다는 차이가 있다.

이 문제 또한 완전탐색으로 해결할 수 있으나, 78번과 똑같이 풀었다간 power set에 중복이 나타날 수 있다.

이를 해결하기 위해 nums를 sorting하고, same_num이라는 변수를 추가하여 중복 원소에 대한 처리를 추가하였다. 아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> subset;
        sort(nums.begin(), nums.end()); //중복 요소를 쉽게 계산하기 위하여 sorting
        answer.push_back(subset);   
        Get_Answer(nums, answer, subset, 0, 1);
        return answer;
    }

    void Get_Answer(vector<int>& nums, vector<vector<int>>& answer, vector<int>& subset, int index, int same_num) {
        if (index >= nums.size())    return;    //배열 범위 벗어나면 종료
        if (index < nums.size() - 1 && nums[index] == nums[index + 1]) {    //다음에 나오는 원소가 현재 원소와 같다면 same_num++
            Get_Answer(nums, answer, subset, index + 1, same_num + 1);
        }
        else {
            for (int a = 1; a <= same_num; a++) {   //같은 수가 여러개인 경우 subset에 1개, 2개, ... same_num개 포함된 경우로 나눈다
                subset.push_back(nums[index]);
                answer.push_back(subset);
                Get_Answer(nums, answer, subset, index + 1, 1);
            }
            for (int a = 1; a <= same_num; a++)   subset.pop_back();
            Get_Answer(nums, answer, subset, index + 1, 1); //현재 index가 가르키는 수를 하나도 사용하지 않는 subset을 구한다
        }
    }
};