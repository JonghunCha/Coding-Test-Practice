/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12979
일종의 완전 탐색 문제로 생각할 수 있다.

우선 n은 최대 200,000,000이기에 n을 일일히 비교하는 것은 시간제한에 걸릴 가능성이 높다.

따라서 stations의 정보를 통해 전파가 전달되지 않는 구간의 길이를 구하고 추가 설치해야될 기지국을 늘려나가야 한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, curr = 0, range;    //curr은 현재 어느 아파트까지 전파가 확실히 전달되는지를 저장, range는 전파가 전달 안되는 구간의 길이를 저장

    for (int a = 0; a < stations.size(); a++) {
        if (stations[a] - w > curr) {   //a번째 기지국의 전파를 받는 첫 아파트보다 현재 아파트가 더 앞에 있는 경우(기지국을 증설해야하는 경우)
            range = stations[a] - w - curr - 1; //몇 개의 아파트가 전파를 못 받는지 계산
            answer += (range / (2 * w + 1));    
            if (range % (2 * w + 1) != 0)  answer++;
        }
        curr = stations[a] + w; //a번째 기지국에서 오른쪽으로 w번째 아파트까지는 전파를 전달 받을 수 있음
    }

    if (curr < n) { //마지막 기지국의 전파를 받는 아파트 이후의 아파트가 남아있는 경우
        range = n - curr;
        answer += (range / (2 * w + 1));
        if (range % (2 * w + 1) != 0)  answer++;
    }

    return answer;
}