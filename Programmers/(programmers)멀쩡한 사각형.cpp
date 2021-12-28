/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/62048
문제를 해결하는 방법만 알면 쉽다.

우선 잘리는 정사각형은 가로와 세로의 최소공배수 만큼 같은 패턴임을 알 수 있다.

또한 하나의 패턴에서 잘리는 정사각형의 수는 해당 패턴의 가로 갯수 + 세로 갯수 - 1이다.

왜냐하면 각 col마다 잘리는 정사각형의 수는 최소 1개이다. 그러나 가로선을 가로지르는 경우엔 2개일 수 있다. 가로선의 갯수는 row의 수 - 1이다.

따라서 col의 수 + (row의 수 - 1)이 잘리는 정사각형의 수가 된다.
*/
using namespace std;

int GCD(int w, int h);

long long solution(int w, int h) {
    long long answer, count;
    int gcd = GCD(w, h), nw = w / gcd, nh = h / gcd;

    answer = (long long)w * (long long)h;
    answer -= gcd * (nw + nh - 1);

    return answer;
}
//w와 h의 최소공배수를 반환하는 함수
int GCD(int w, int h) {
    int big, small, temp;
    if (w > h) {
        big = w;
        small = h;
    }
    else {
        big = h;
        small = w;
    }

    while (1) {
        if (big % small == 0)    return small;
        temp = big - small;
        if (temp > small)    big = temp;
        else {
            big = small;
            small = temp;
        }
    }
}