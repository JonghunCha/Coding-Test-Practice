/*
���� ��ũ : https://leetcode.com/problems/jump-game/
Dynamic Programming���� �ذ��� �� �ִ� ������.

ȥ�� ������ ���̵��� �������� �� ����� ������ �ð��� �� ���� �ɷ��� �ٸ� ����� �ø� �ڵ带 ���Ҵ�.

�ش� �ڵ带 ���� �ܼ������� ����� �������� �ð� �� �޸� complexity�� ���� �� �ִٴ� ���� �˰� �Ǿ���.

�Ʒ����� �� ���� �ڵ带 ��� �ø��ڴ�. ���ݸ� ��� �����ϸ� �ξ� ȿ������ �ڵ带 © �� �ִٴ� ���� �����.
*/

//ó�� ���� ���
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)    return true;
        int n = nums.size();
        bool answer[n]; //�� index���� ����ؼ� �� ������ ������ �� �ִ����� ����

        for (int a = 0; a < n; a++)  answer[a] = false;
        for (int a = n - 2; a >= 0; a--) Get_Answer(nums, a, answer);   //�ڿ������� �������� ������ �� �ִ��� ���

        return answer[0];
    }

    void Get_Answer(vector<int>& nums, int index, bool* answer) {
        if (index + nums[index] >= nums.size() - 1) {   //���� index�������� �ٷ� �������� ���� �����ϴٸ� answer[index]�� true�� ����
            answer[index] = true;
            return;
        }

        for (int a = 1; a <= nums[index]; a++) {    //���� �ش���� �ʴ� ��� index���� �� �� �ְ� �̹� ���� ������ true�� �ִ��� Ȯ��
            if (answer[index + a] == true) {
                answer[index] = true;
                return;
            }
        }
    }
};

//�ٸ� ����� ���
//�� ������� �ڿ������� ���Ǹ� �� ������ ���� ������ ������ �ִٸ� �ش� �κ��� �� �������� �ٲ۴�.
//�̷��� ����� ���ؼ� ���� ������� ����� bool�� �迭�� ����� �ʿ䵵 ����, �� ������ ���� �Լ�ȣ���� ���� �ʰ� �ѹ��� �ذ��� �� �ִ�.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), last = n - 1, i, j;
        for (i = n - 2; i >= 0; i--) {  
            if (i + nums[i] >= last)last = i;
        }
        return last <= 0;
    }
};