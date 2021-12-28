/*
���� ��ũ : https://leetcode.com/problems/3sum/
Two Pointers�� �ذ��� �� �ִ� ������.

ó���� Ǭ ����� �־�����, �ش� ������� �ٸ� ����� Ǯ�̰� �ξ� ����ϰ� ����ӵ��� ���� �ٸ� ���� ���̵� ������� �ۼ��� �ڵ��̴�.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int sum, left, right;

        if (nums.size() < 3) return ret;

        sort(nums.begin(), nums.end()); //������������ ����

        for (int a = 0; a < nums.size() - 2; a++) {
            //�ߺ��� Ž���� �����ϱ� ���� ������ Ž���� nums[a-1]�� �̹� ������ nums[a]�� ���ٸ� �׳� �Ѿ��.
            if (a > 0 && nums[a] == nums[a - 1])    continue;   
            left = a + 1;   //�� ��° ���� ��ġ
            right = nums.size() - 1;    //�� ��° ���� ��ġ
            while (left < right) {
                sum = nums[a] + nums[left] + nums[right];   //������ ���� ���Ѵ�
                if (sum > 0) right--;   //���� ���� 0���� ũ�ٸ� ���� ū ���� ��Ÿ���� right�� ��ĭ �������� ����
                else if (sum < 0)    left++;    //���� �ݴ��� ���
                else {  //���� 0�� ������ ���� ã�� ���
                    ret.push_back(vector<int>{nums[a], nums[left], nums[right]});   //������ ����
                    //���������� �ߺ��� ����� �����ϱ� ���� ���� left Ȥ�� right�� ��Ÿ���� ���� ���� ���� �ѱ�
                    while (left + 1 < right && nums[left] == nums[left + 1])   left++;  
                    while (right - 1 > left && nums[right] == nums[right - 1])   right--;
                    left++;
                    right--;
                }
            }
        }
        return ret;
    }
};