/*
문제 링크 : https://leetcode.com/problems/container-with-most-water/
Two Pointers개념으로 해결할 수 있다.

가장 먼저 넓이가 제일 넓은 지역부터 탐색한다.

넓이를 줄이고 물의 양을 많게 하기 위해선 높이가 무조건 높아져야 한다.

따라서 바깥쪽에서 안쪽의 높이를 살피며 기존에 계산된 높이보다 낮은 부분은 건너뛰고, 높은 경우 물의 양을 계산한 뒤 정답을 갱신하면 된다.
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