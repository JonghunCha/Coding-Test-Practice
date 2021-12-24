/*
문제 링크 : https://leetcode.com/problems/happy-number/
어느 파트로 분류하기 애매한 문제이나, 수랑 관련되어서 math에 넣었다.

핵심은 1이 나올때까지 반복하다가 만약 loop에 빠졌다면은 false를 반환하면 된다.

loop에 빠졌다는 것은 이전에 나왔던 수가 다시 나왔다는 뜻이고, 이를 판단하기 최적의 자료구조는 unordered_set을 사용하는 것이다.
*/
class Solution {
public:
    bool isHappy(int n) {
        int num = n, temp;
        unordered_set<int> s;
        //num이 1이 될때까지 반복
        while (num != 1) {
            temp = 0;
            while (num > 0) {   //num의 각 숫자를 제곱하여 temp에 더해준다
                temp += (num % 10) * (num % 10);
                num = num / 10;
            }
            num = temp;
            if (s.find(num) == s.end())  s.insert(num); //s에 num이 없다면 추가
            else    return false;   //이미 나왔던 수라면 false 반환
        }

        return true;
    }
};