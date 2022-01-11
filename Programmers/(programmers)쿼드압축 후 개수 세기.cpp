/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/68936
큐를 이용하여 해결한 문제다.

우선 arr전체 범위를 큐에 넣는다.(큐에 arr 그 자체를 넣는 것이 아닌 arr의 왼쪽 위 지점, 오른쪽 아래 지점의 좌표를 저장)

그런 다음 아래 동작을 큐가 비어있게 될 때까지 반복한다.

1. 큐의 front에서 특정 영역 S를 추출
	1-1. 해당 지역이 전부 같은 수라면 카운팅하고 while반복
	1-2. 해당 지역이 전부 같은 수가 아니라면 4영역으로 나눈 좌표를 다시 큐에 push()
*/
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

bool isAllsame(vector<vector<int>>& arr, int x1, int y1, int x2, int y2);

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int zero_num = 0, one_num = 0, len = arr.size(), x1, y1, x2, y2;
    queue<tuple<int, int, int, int>> q;

    q.push(make_tuple(0, 0, len - 1, len - 1)); //전체 영역을 큐에 push
    while (!q.empty()) {
        x1 = get<0>(q.front());
        y1 = get<1>(q.front());
        x2 = get<2>(q.front());
        y2 = get<3>(q.front());
        q.pop();

        if (isAllsame(arr, x1, y1, x2, y2)) {   //만약 현재 영역이 모두 같은 숫자라면 해당 숫자에 맞는 카운트를 ++
            if (arr[x1][y1] == 0)    zero_num++;
            else    one_num++;
        }
        else {  //만약 현재 영역이 모두 같은 숫자가 아닌 경우
            if (x2 - x1 == 1) { //현재 영역이 2*2인 경우 4개로 나누었을 때 더 이상 나눌 것이 없으므로 바로 카운팅
                for (int a = x1; a <= x2; a++) {
                    for (int b = y1; b <= y2; b++) {
                        if (arr[a][b] == 0)  zero_num++;
                        else    one_num++;
                    }
                }
            }
            else {  //4개 영역을 큐에 push
                q.push(make_tuple(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2));
                q.push(make_tuple(x1, ((y1 + y2) / 2) + 1, (x1 + x2) / 2, y2));
                q.push(make_tuple(((x1 + x2) / 2) + 1, y1, x2, (y1 + y2) / 2));
                q.push(make_tuple(((x1 + x2) / 2) + 1, ((y1 + y2) / 2) + 1, x2, y2));
            }
        }
    }

    answer.push_back(zero_num);
    answer.push_back(one_num);

    return answer;
}
//(x1, y1)좌표부터 (x2, y2)좌표까지의 영역이 모두 같은 숫자인지 확인하는 함수
bool isAllsame(vector<vector<int>>& arr, int x1, int y1, int x2, int y2) {
    int temp = arr[x1][y1];

    for (int a = x1; a <= x2; a++) {
        for (int b = y1; b <= y2; b++) {
            if (arr[a][b] != temp)   return false;
        }
    }

    return true;
}