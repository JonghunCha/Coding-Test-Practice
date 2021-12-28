/*
문제 링크 : https://leetcode.com/problems/reverse-bits/
비트마스킹으로 해결할 수 있는 문제다.

비트를 뒤집기 위해서 temp라는 변수를 하나 두었다. temp에서 각 스텝마다 옮기려고하는 위치의 비트를 제외하곤 전부 0으로 만들어 주었다.

그런 다음 해당 비트가 뒤집혔을 때 위치할 곳으로 시프트연산을 통해 이동하였다.
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        uint32_t temp;
        //실행 속도를 위해 좌측과 우측을 나누어서 구현하였다.
        for (int a = 0; a < 16; a++) {
            temp = n >> a;
            temp = temp << 31;
            temp = temp >> a;
            answer = answer | temp;
        }
        for (int a = 0; a < 16; a++) {
            temp = n << a;
            temp = temp >> 31;
            temp = temp << a;
            answer = answer | temp;
        }
        return answer;
    }
};