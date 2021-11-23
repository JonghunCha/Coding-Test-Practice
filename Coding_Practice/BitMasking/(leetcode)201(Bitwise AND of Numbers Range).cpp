/*
문제 링크 : https://leetcode.com/problems/bitwise-and-of-numbers-range/
BitMasking으로 해결할 수 있는 문제다.

left와 right사이는 연속된 수들이고 left보다 right가 크다.

따라서 모든 수를 &연산 하면 왼쪽 비트부터 살펴봤을 때 left와 right가 일치하는 동안의 비트만 살아남게 된다.

결국, left와 right가 일치할 때까지 >> 연산을 해주고, 같아지는 순간에 >>연산을 한 만큼 <<연산을 해주면 된다.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }

        left <<= count;

        return left;
    }
};