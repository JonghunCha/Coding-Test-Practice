/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43238
이진 탐색으로 해결할 수 있는 문제다.

제한사항에 따르면 정답의 범위는 0~1,000,000,000,000,000,000 사이이다.

위의 범위를 일일히 확인하는 것은 엄청난 시간을 요한다.

따라서 이진 탐색을 통해서 최초로 n명의 입국 심사를 마칠 수 있는 시간을 찾으면 된다.
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 0, right = 1000000000000000000, middle, temp;

    while (left < right) {
        middle = (left + right) / 2;
        temp = 0;
        for (int a = 0; a < times.size(); a++) {
            temp += middle / times[a];
        }

        if (temp >= n)   right = middle;    //만약 n명 이상의 입국심사를 마칠 수 있다면 시간의 범위를 left~middle로 설정
        else    left = middle + 1;  //만약 n명의 입국심사를 마칠 시간이 안된다면 시간의 범위를 middle~right로 설정
    }

    return left;
}