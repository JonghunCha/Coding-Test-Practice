/*
���� ��ũ : https://leetcode.com/problems/subsets-ii/
(leetcode)78�� ������ ���� ��������� �ʱ� �迭�� �ߺ� ��Ұ� ���� �� �ִٴ� ���̰� �ִ�.

�� ���� ���� ����Ž������ �ذ��� �� ������, 78���� �Ȱ��� Ǯ���ٰ� power set�� �ߺ��� ��Ÿ�� �� �ִ�.

�̸� �ذ��ϱ� ���� nums�� sorting�ϰ�, same_num�̶�� ������ �߰��Ͽ� �ߺ� ���ҿ� ���� ó���� �߰��Ͽ���. �Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> subset;
        sort(nums.begin(), nums.end()); //�ߺ� ��Ҹ� ���� ����ϱ� ���Ͽ� sorting
        answer.push_back(subset);   
        Get_Answer(nums, answer, subset, 0, 1);
        return answer;
    }

    void Get_Answer(vector<int>& nums, vector<vector<int>>& answer, vector<int>& subset, int index, int same_num) {
        if (index >= nums.size())    return;    //�迭 ���� ����� ����
        if (index < nums.size() - 1 && nums[index] == nums[index + 1]) {    //������ ������ ���Ұ� ���� ���ҿ� ���ٸ� same_num++
            Get_Answer(nums, answer, subset, index + 1, same_num + 1);
        }
        else {
            for (int a = 1; a <= same_num; a++) {   //���� ���� �������� ��� subset�� 1��, 2��, ... same_num�� ���Ե� ���� ������
                subset.push_back(nums[index]);
                answer.push_back(subset);
                Get_Answer(nums, answer, subset, index + 1, 1);
            }
            for (int a = 1; a <= same_num; a++)   subset.pop_back();
            Get_Answer(nums, answer, subset, index + 1, 1); //���� index�� ����Ű�� ���� �ϳ��� ������� �ʴ� subset�� ���Ѵ�
        }
    }
};