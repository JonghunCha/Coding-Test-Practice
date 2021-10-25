/*
���� ��ũ : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Two Pointers�� �ذ��� �� �ִ� ������.

numbers�� ũ�Ⱑ �ִ� 30000�̱⿡ �ܼ��� for������ ��ü�� Ž���ϴ� ����� �ð��ʰ��� ���´�.

�̴� two pointers�� �̿������ν� �ʿ���� Ž���� ���� �������ν� �ذ��� �� �ִ�.

���� ù ��° �����ʹ� numbers�� ������, �� ��° �����ʹ� numbers�� ���� ����Ų��.

�׷� ���� �� �����Ͱ� ����Ű�� ����� ���� target�� �� ������ �Ʒ��� �ݺ��Ѵ�.
1. sum < target -> �� ū ���� �ʿ��ϱ⿡ ���ۿ� ����� �����͸� 1 Ű���
2. sum > target -> �� ���� ���� �ʿ��ϱ⿡ ���� ����� �����͸� 1 �����
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int left = 0, right = numbers.size() - 1, sum;

        while (1) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                answer.emplace_back(left + 1);
                answer.emplace_back(right + 1);
                break;
            }
            else if (sum < target)   left++;
            else    right--;
        }
        return answer;
    }
};