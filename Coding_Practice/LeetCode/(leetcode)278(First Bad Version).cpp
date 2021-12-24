/*
문제 링크 : https://leetcode.com/problems/first-bad-version/
Binary Search로 해결할 수 있는 문제다.
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long begin = 1, end = n, middle;
        while (begin <= end) {
            middle = (begin + end) / 2;
            if (isBadVersion(middle))    end = middle - 1;
            else    begin = middle + 1;
        }
        return begin;
    }
};