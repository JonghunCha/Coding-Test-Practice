/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1831
3단고음 규칙을 잘 이해하면 쉽게 해결할 수 있다.

3단 고음 문자열을 뒤에서부터 맞추어 나가며, 현재까지 사용한 *의 갯수를 star_num, +의 갯수를 plus_num이라 하자.

*을 추가하기 위해선 현재 num이 3으로 나누어 떨어져야하며, star_num < (plus_num / 2)를 만족해야한다.

+를 추가하기 위해선 pow((plus_num / 2) - star_num)이 현재 num보다 작아야한다.
(이는 3단 고음 문자열을 만족하기 위해 앞으로 추가해야 할 *들로 인해 현재 num보다 커지면 안되기 때문)
*/
#include <iostream>
using namespace std;

int answer;

void check(int num, int star_num, int plus_num);
long long pow3(int times);

int solution(int n) {
    answer = 0;
    check(n - 2, 0, 2);

    return answer;
}

void check(int num, int star_num, int plus_num) {
    //만약 문자열이 문제의 조건을 만족하면 answer++
    if (num == 1 && (star_num * 2) == plus_num)  answer++;  
    //*을 추가할 수 있는 경우 *을 추가하고 다음 재귀 진행
    if (star_num < (plus_num / 2) && num % 3 == 0) {    
        check(num / 3, star_num + 1, plus_num);
    }
    //+를 추가할 수 있는 경우 +을 추가하고 다음 재귀 진행
    if (pow3((plus_num / 2) - star_num) < num) {
        check(num - 1, star_num, plus_num + 1);
    }
}
//3의 times승을 반환
long long pow3(int times) {
    long long ret = 1;

    for (int a = 0; a < times; a++) {
        ret *= 3;
    }

    return ret;
}