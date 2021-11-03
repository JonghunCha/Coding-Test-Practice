/*
문제 링크 : https://leetcode.com/problems/number-of-1-bits/
& 와 >> 비트연산자를 이용하여 해결할 수 있다.

&연산자는 모든 비트의 and연산을 하는데, n&1은 맨 오른쪽 비트가 둘다 1일때는 1이되고 그 반대는 0이된다.

이 점을 이용하여 맨 오른쪽 비트가 1인지 검사하고 그 다음엔 오른쪽으로 1씩 시프트하며 32개의 비트를 다 비교하면 된다.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while (n) {
            if (n & 1 == 1)    answer++;
            n >>= 1;
        }
        return answer;
    }
};