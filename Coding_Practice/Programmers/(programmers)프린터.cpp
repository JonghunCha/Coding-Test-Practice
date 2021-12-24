/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42587
ť�� �̿��ϸ� ���� �ذ��� �� �ִ� ������.

�켱 ���� ������� index�� priority�� ť�� ������� �ִ´�.

�׷� ���� location�� �ش��ϴ� ����Ʈ�� ������ ������ �Ʒ��� �ݺ��Ѵ�.

1. ť�� front�� priority�� ���� ũ�ٸ� ����Ʈ�� �Ѵ�. �� �� location�� index�� ���ٸ� count�� ��ȯ�Ѵ�.
2. �� �ʿ� �켱������ �� ū ������ �ִٸ� pop()�� �ڿ� �ٽ� push()�Ѵ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<tuple<int, int>> q;
    int highest, count = 0, priority, index;    //higest�� ���� ���� �켱������ ���� �ǹ�
    //ť�� ������ �ֱ�
    for (int a = 0; a < priorities.size(); a++) {
        q.push(make_tuple(a, priorities[a]));
    }
    //location�� ����� ������ �ݺ�
    while (!q.empty()) {
        //���� ���� �켱���� ��ȣ ã��
        highest = 0;
        for (int a = 0; a < priorities.size(); a++) {
            if (priorities[a] > highest) highest = priorities[a];
        }
        //���� ť�� front�� �ִ� ������ ó��
        index = get<0>(q.front());
        priority = get<1>(q.front());
        if (priority == highest) {  //�켱������ ���� ���ٸ� ����Ʈ
            count++;
            if (index == location)   return count;  //���ϴ� location�� ������� �ٷ� count��ȯ
            else {  //���� location�� ������ �ƴ϶�� priority�� 0���� �����ϰ� ť���� ����
                priorities[index] = 0;
                q.pop();
            }
        }
        else {  //�켱������ ���� ���� �ʴٸ� ť�� �� �ڷ� �̵�
            q.pop();
            q.push(make_tuple(index, priority));
        }
    }

    return count;
}