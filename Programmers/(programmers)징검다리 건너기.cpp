/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/64062
징검다리를 못 건너는 순간은 연속한 k개의 징검다리의 숫자가 0이 되는 경우다.

이는 k개의 연속한 징검다리 중 가장 큰 숫자만큼의 사람이 지나갔을 경우 해당 구간은 건널수 없는 구간이 된다.

k개의 연속한 징검다리 구간은 여러개 있을 것이고 각 구간마다 가장 큰 값을 가진 징검다리가 있을 것이다.

각 구간은 가장 큰 값을 가진 징검다리의 수만큼의 사람이 지나가면 해당 구간은 k길이의 점프로도 지나갈 수 없는 구간이 된다.

따라서, 정답은 모든 각 구간들의 가장 큰 값들 중 가장 작은 값이다.

징검다리의 수는 최대 20만개이고, k또한 최대 20만 이기에 2중 포문을 사용하면 시간초과가 일어날 가능성이 높다.

이를 해결하기 위해 map을 사용하여 sliding window형식으로 구현하였다.
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int section_max, entire_min = 200000001;
    map<int, int> m;
    //첫 k개 map에 넣기
    for (int a = 0; a < k; a++) {
        if (m.find(stones[a]) == m.end()) {
            m[stones[a]] = 1;
        }
        else {
            m[stones[a]]++;
        }
    }
    //a가 k번 인덱스부터 끝까지 반복하며 새로운 징검다리는 map에 넣고 가장 왼쪽의 징검다리는 map에서 제거
    for (int a = k; a < stones.size(); a++) {
        //현재 구간에서 가장 큰 값이 현재 entire_min보다 작다면 갱신
        section_max = m.rbegin()->first;
        if (section_max < entire_min)    entire_min = section_max;
        //새로운 징검다리를 map에 넣는다
        if (m.find(stones[a]) == m.end()) {
            m[stones[a]] = 1;
        }
        else {
            m[stones[a]]++;
        }
        //가장 왼쪽의 징검다리를 map에서 제거
        m[stones[a - k]]--;
        if (m[stones[a - k]] == 0) {
            m.erase(stones[a - k]);
        }
    }
    section_max = m.rbegin()->first;
    if (section_max < entire_min)    entire_min = section_max;

    return entire_min;
}