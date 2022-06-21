/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42583
ť�� �̿��Ͽ� �ٸ��� �ö� �ִ� Ʈ���� ��� �ð� ������ �����ϸ� ���� �ذ��� �� �ִ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, index = 1, total_weight = 0;
    queue<pair<int, int>> q;

    //ù Ʈ�� ť�� �ֱ�
    q.push(make_pair(1, truck_weights[0]));
    total_weight = truck_weights[0];
    while (!q.empty()) {    //��� Ʈ���� ���������� �ݺ�
        answer++;
        //���� ���� Ʈ���� �ٸ��� ������ ���� ���
        if (q.front().first + bridge_length <= answer) {
            total_weight -= q.front().second;
            q.pop();
        }

        //���ο� Ʈ���� �ٸ��� �ö� �� �ִ� ���
        if (index < truck_weights.size() && total_weight + truck_weights[index] <= weight) {
            q.push(make_pair(answer, truck_weights[index]));
            total_weight += truck_weights[index];
            index++;
        }
    }

    return answer;
}