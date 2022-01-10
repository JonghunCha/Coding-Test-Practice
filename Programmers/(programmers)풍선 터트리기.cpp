/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/68646
문제의 핵심은 숫자가 작은 풍선은 단 한번만 터트릴 수 있다는 것이다.

따라서 배열에서 제일 작은 수가 아닌 풍선은 제일 작은 풍선을 만났을 때 작은 풍선을 터트려야 최후의 풍선이 될 수 있다.

풍선이 1번~N번 까지 있고, 제일 작은 풍선이 x번에 있다고 가정하자.

그렇다면 제일 작은 풍선보다 오른쪽에 있는 풍선은 자신보다 오른쪽에 있는 풍선들중 제일 작다면 제일 작은 풍선과 만날 수 있다.(왼쪽은 제일 작은 풍선이 다 터트릴 것이기에)

반대로 제일 작은 풍선보다 왼쪽에 있는 풍선은 자신보다 왼쪽에 있는 풍선들 중 제일 작다면 최후의 풍선이 될 수 있는 것이다.

이러한 아이디어를 이용하여 정답을 구한 코드가 아래와 같다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> input) {
    int answer = 0, min_val = 1000000000, min_idx = 0, min_val_curr;
    //가장 작은 풍선의 값과 인덱스를 구한다
    for (int a = 0; a < input.size(); a++) {
        if (input[a] < min_val) {
            min_val = input[a];
            min_idx = a;
        }
    }
    //가장 왼쪽, 오른쪽, 가장 작은 풍선은 항상 최후의 풍선이 될 수 있다
    if (min_idx == 0 || min_idx == input.size() - 1) {  //가장 작은 풍선이 배열의 끝에 위치한 경우
        answer += 2;
    }
    else {  //가장 작은 풍선이 배열의 끝이 아닌곳에 위치한 경우
        answer += 3;
    }
    //왼쪽부터 탐색하며 해당 인덱스의 풍선이 현재까지나온 풍선중 가장 작다면 최후의 풍선이 될 수 있음
    min_val_curr = input[0];
    for (int a = 1; a < min_idx; a++) {
        if (input[a] < min_val_curr) {
            answer++;
            min_val_curr = input[a];
        }
    }
    //오른쪽의 경우
    min_val_curr = input[input.size() - 1];
    for (int a = input.size() - 2; a > min_idx; a--) {
        if (input[a] < min_val_curr) {
            answer++;
            min_val_curr = input[a];
        }
    }

    return answer;
}