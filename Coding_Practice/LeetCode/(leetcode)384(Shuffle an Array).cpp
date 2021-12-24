/*
���� ��ũ : https://leetcode.com/problems/shuffle-an-array/
�ܼ� rand()�Լ��� ����� ���� ������.

�־��� vector���� �� ���ҵ��� rand()�� ���� index�� �ִ� ���ҿ� ������ �����ν� shuffle�Լ��� �����Ͽ���.
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