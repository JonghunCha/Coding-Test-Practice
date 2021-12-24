/*
문제 링크 : https://leetcode.com/problems/shuffle-an-array/
단순 rand()함수의 사용을 묻는 문제다.

주어진 vector에서 각 원소들을 rand()로 구한 index에 있는 원소와 스왑을 함으로써 shuffle함수를 구성하였다.
*/
class Solution {
public:
    vector<int> num;

    Solution(vector<int>& nums) {
        this->num = nums;
    }

    vector<int> reset() {
        return num;
    }

    vector<int> shuffle() {
        vector<int> ret;
        int target;

        ret = num;

        for (int a = 0; a < ret.size(); a++) {
            target = rand() % ret.size();
            swap(ret[target], ret[a]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */