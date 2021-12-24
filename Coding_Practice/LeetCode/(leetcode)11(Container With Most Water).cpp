/*
���� ��ũ : https://leetcode.com/problems/container-with-most-water/
Two Pointers�������� �ذ��� �� �ִ�.

���� ���� ���̰� ���� ���� �������� Ž���Ѵ�.

���̸� ���̰� ���� ���� ���� �ϱ� ���ؼ� ���̰� ������ �������� �Ѵ�.

���� �ٱ��ʿ��� ������ ���̸� ���Ǹ� ������ ���� ���̺��� ���� �κ��� �ǳʶٰ�, ���� ��� ���� ���� ����� �� ������ �����ϸ� �ȴ�.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0, left = 0, right = height.size() - 1, h;
        while (left < right) {
            h = min(height[left], height[right]);
            answer = max(answer, h * (right - left));
            while (height[left] <= h && left < right)    left++;
            while (height[right] <= h && left < right)   right--;
        }
        return answer;
    }
};