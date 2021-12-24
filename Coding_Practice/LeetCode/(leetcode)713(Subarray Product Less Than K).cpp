/*
문제 링크 : https://leetcode.com/problems/subarray-product-less-than-k/
Sliding Window로 해결할 수 있는 문제다.

아래 코드를 보면 금방 이해할 수 있을 것이다.
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int answer = 0, product = 1, left = 0;  //left는 현재 탐색중인 subarray에서 가장 왼쪽의 index를 의미

        if (k <= 1)  return 0;
        for (int a = 0; a < nums.size(); a++) {
            product *= nums[a];
            while (product >= k) {  //새로운 a번째 index의 값을 곱했을 때 k를 넘는다면 아래 과정을 반복하며 answer를 갱신
                product /= nums[left];
                answer += a - left; //a번째 index의 수가 곱해지기 전에 left로부터 시작하여 a-1번째 까지 곱셈은 모두 k를 넘지 않았다
                left++;
            }
        }
        if (nums.size() > left) {   //위의 반복문을 빠져 나온 뒤, 아직 answer에 추가되지 않은 정답들을 추가
            for (int a = 1; a <= nums.size() - left; a++) answer += a;
        }

        return answer;
    }
};