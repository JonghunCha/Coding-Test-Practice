/*
문제 링크 : https://leetcode.com/problems/power-of-two/
비트마스킹으로 간단하게 해결할 수 있는 문제다.

반복문으로도 해결할 수 있지만 비트마스킹을 이용하면 훨씬 더 빠르고 짧은 코드를 작성할 수 있다.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)  return false;
        return !(n & (n - 1));
    }
};