/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43163
BFS로 해결할 수 있는 문제다.

가장 짧은 변환을 찾기 위해서 begin부터 가능한 변환을 모두 큐에 넣는다.

그런 다음 target으로의 변환이 이루어 질 때까지 큐에서 하나를 뽑아 변환을 한 뒤 큐의 맨 뒤에 넣어주는 작업을 반복하면 된다.
*/
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int visited[50], diff_num, curr;
    string temp;
    queue<pair<string, int>> q;
    bool isfind = false;
    //특정 단어가 이미 변환 된 적 있는지를 나타내는 visited 초기화
    for (int a = 0; a < words.size(); a++)  visited[a] = 0;
    //begin단어에서 변환 될 수 있는 단어를 큐에 넣고 visited를 1로 설정
    for (int a = 0; a < words.size(); a++) {
        diff_num = 0;
        for (int b = 0; b < begin.size(); b++) {
            if (begin[b] != words[a][b]) diff_num++;
        }
        if (diff_num == 1) {
            q.push(make_pair(words[a], 1));
            visited[a] = 1;
        }
    }
    //target단어를 찾으면 정답을 반환, 큐가 빌때까지 반복
    while (!q.empty()) {
        temp = q.front().first;
        curr = q.front().second;
        q.pop();
        if (temp.compare(target) == 0)   return curr;   //만약 현재 단어가 target단어라면 정답 반환
        //현재 단어인 temp에서 변환 가능한 단어를 큐에 추가
        for (int a = 0; a < words.size(); a++) {
            diff_num = 0;
            if (visited[a] == 0) {
                for (int b = 0; b < temp.size(); b++) {
                    if (temp[b] != words[a][b])  diff_num++;
                }
                if (diff_num == 1) {
                    q.push(make_pair(words[a], curr + 1));
                    visited[a] = 1;
                }
            }
        }
    }
    //큐가 비어서 while문을 빠져 나온 것은 target단어로의 변환이 불가능 하다는 것
    return 0;
}