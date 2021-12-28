/*
문제 링크 : https://leetcode.com/problems/squares-of-a-sorted-array/
Two Pointers로 해결할 수 있는 문제다.

정렬된 integer 배열이 주어지고 해당 배열 요소의 제곱 값이 오름차순으로 정렬된 배열을 반환해야한다.

우선 모든 배열 원소들을 제곱하며 가장 작은 값의 위치를 알아낸다.

그런 다음 가장 작은 값의 위치 왼쪽과 오른쪽을 비교하며 더 작은 값을 ret벡터에 넣어주는 방식으로 해결하면 된다.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int min = 10000000000, min_index, left, right;
        vector<int> ret;
        //제곱값을 구하며 최솟값도 동시에 계산
        for (int a = 0; a < nums.size(); a++) {
            nums[a] *= nums[a];
            if (nums[a] < min) {
                min = nums[a];
                min_index = a;
            }
        }
        //최솟값을 ret벡터에 넣어주고 left와 right를 min_index 좌,우로 지정
        ret.emplace_back(nums[min_index]);
        left = min_index - 1;
        right = min_index + 1;
        //left나 right중 하나라도 유효한 index일 때까지 반복
        while (left >= 0 || right < nums.size()) {
            if (left < 0)    ret.emplace_back(nums[right++]);   //min_index 왼쪽의 값이 모두 ret에 들어간 경우
            else if (right >= nums.size())   ret.emplace_back(nums[left--]);    //min_index 오른쪽의 값이 모두 ret에 들어간 경우
            else {
                if (nums[left] < nums[right])    ret.emplace_back(nums[left--]);
                else    ret.emplace_back(nums[right++]);
            }
        }
        return ret;
    }
};