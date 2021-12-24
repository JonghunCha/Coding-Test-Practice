/*
���� ��ũ : https://leetcode.com/problems/permutations-ii/
�ߺ��� �ִ� �迭�� ��� permutation�� ���ϴ� ������.

recursion�� ���� �ذ��� �� �ִ�.

����, nums���� ���� ������ map���� �����. �׷� ���� map�� value���� 0���� ū key������ permuation�� �ְ� ���� ������� ��� permutation�� ���� �� �ִ�.
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> permutation;
        map<int, int> m;
        //nums�� �ִ� ���� �� ���� ������ map�� key value�� ����
        for (int a = 0; a < nums.size(); a++) {
            if (m.find(nums[a]) == m.end())  m[nums[a]] = 0;
            m[nums[a]]++;
        }
        Get_Answer(answer, permutation, m, nums.size());

        return answer;
    }

    void Get_Answer(vector<vector<int>>& answer, vector<int>& permutation, map<int, int>& m, int num) {
        if (num == 0)    answer.push_back(permutation); //permutation�� �ϼ��� ���

        for (map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second != 0) { //value���� 0�� �ƴ� ���
                permutation.push_back(itr->first);  //permutation�� ���� ����
                itr->second--;
                Get_Answer(answer, permutation, m, num - 1);    //recursion
                permutation.pop_back(); 
                itr->second++;
            }
        }
    }
};