/*
문제 링크 : https://leetcode.com/problems/single-number/
비트마스킹을 사용하면 짧은 코드로 해결할 수 있다.

비트 연산자중 XOR연산자를 이용하면 된다.

주어진 배열에서 똑같은 수는 xor을 거치면 다 0이 된다.(A^A = 0)

따라서 배열의 모든 수를 xor연산을 거치게 하면 2개씩 있는 수는 모두 0으로 지워질 것이고 결국 하나만 존재하는 수가 남게 된다.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = nums[0];
        for (int a = 1; a < nums.size(); a++) {
            answer = answer ^ nums[a];
        }
        return answer;
    }
};