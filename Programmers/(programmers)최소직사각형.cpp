/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/86491
굉장히 쉬운 문제라 풀까 말까 고민한 문제다.

주어진 sizes의 각 원소에서 큰 값은 0번째 인덱스에, 작은 값은 1번째 인덱스에 가도록 하였다.

그런 다음 0번째 인덱스중 가장 큰 값과 1번째 인덱스중 가장 큰 값을 곱하면 정답이다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int temp, max_w = 0, max_h = 0;

    for (int a = 0; a < sizes.size(); a++) {
        if (sizes[a][0] < sizes[a][1]) {
            temp = sizes[a][0];
            sizes[a][0] = sizes[a][1];
            sizes[a][1] = temp;
        }
    }

    for (int a = 0; a < sizes.size(); a++) {
        if (sizes[a][0] > max_w) max_w = sizes[a][0];
        if (sizes[a][1] > max_h) max_h = sizes[a][1];
    }

    return max_w * max_h;
}