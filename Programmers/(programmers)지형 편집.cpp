/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12984
이분 탐색으로 해결해야하는 문제다.

각 칸에 놓일 수 있는 블록의 수가 0 이상 10억 이하의 정수이기에, 일일히 탐색하는 것은 시간초과에 걸린다.

문제의 특성상 정답에 가까워질수록 비용도 줄어든다.(정답에 가까울수록 쌓고 제거하는 것에 의한 비용이 줄어들기 때문)

따라서 최소비용은 0 ~ 10억 사이의 이분 탐색으로 찾을 수 있다.
*/
#include <vector>
#include <algorithm>
using namespace std;

long long getCost(vector<vector<int>>& land, int P, int Q, int height);

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = 9000000000000000, val1, val2;
    int low = 0, high = 1000000000, mid;
    //최소 비용 탐색
    while (low < high) {
        mid = (low + high) / 2;

        val1 = getCost(land, P, Q, mid);
        val2 = getCost(land, P, Q, mid + 1);

        if (val1 < val2) {  //val1이 val2보다 작다는 것은 정답은 low ~ val1사이에 있음을 의미
            high = mid;
            answer = min(answer, val1);
        }
        else {  //val1이 val2보다 크거나 같다는 것은 정답은 val2 ~ high사이에 있음을 의미
            low = mid + 1;
            answer = min(answer, val2);
        }
    }

    return answer;
}
//height에 따라 쌓고 제거하는데 드는 비용을 반환하는 함수
long long getCost(vector<vector<int>>& land, int P, int Q, int height) {
    long long ret = 0;

    for (int a = 0; a < land.size(); a++) {
        for (int b = 0; b < land.size(); b++) {
            if (land[a][b] > height) {
                ret += ((long long)land[a][b] - (long long)height) * (long long)Q;
            }
            else if (land[a][b] < height) {
                ret += ((long long)height - (long long)land[a][b]) * (long long)P;
            }
        }
    }

    return ret;
}