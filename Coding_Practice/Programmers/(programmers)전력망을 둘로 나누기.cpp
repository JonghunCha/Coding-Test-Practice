/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/86971
���� Ž������ �ذ��� �� �ִ� ������.

ù ��° �ܰ�� ��� �������� �ϳ��� ���� ������� ���� Ž���� �����Ѵ�.

�� ��° ���� �ܰ��(������ ���� ��) �ϳ��� ���¸� ��Ʈ��ũ�� �� ���� ����ž�� �ִ����� Ȯ���ؾ� �Ѵ�.

�� �κ��� BFS�� ���� �ϳ��� ��Ʈ��ũ�� �� ���� ����ž�� �ִ����� �˾Ƴ� �� �ִ�.

���� �� ���¸� ��Ʈ��ũ ������ ����ž ���� ���̸� ����ϰ� ù ��° ����Ž���� �����ϸ� �ּڰ��� �����ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 100;

int get_diff(int n, int connected[101][101]);

int solution(int n, vector<vector<int>> wires) {
    int connected[101][101], diff;
    //����ž ������ ������ �����ϴ� connected �ʱ�ȭ
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            connected[a][b] = 0;
        }
    }
    //���� ����� ����ž�� connected�� 1�� ����
    for (int a = 0; a < wires.size(); a++) {
        connected[wires[a][0]][wires[a][1]] = 1;
        connected[wires[a][1]][wires[a][0]] = 1;
    }
    //��� ������ ���� �ش� ������ ������ �� ����ž ������ ���̸� ����ϰ� ������ �ּڰ����� ����
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (connected[a][b] == 1) {
                connected[a][b] = 0;
                connected[b][a] = 0;
                diff = get_diff(n, connected);
                if (diff < answer)   answer = diff;
                connected[a][b] = 1;
                connected[b][a] = 1;
            }
        }
    }

    return answer;
}

int get_diff(int n, int connected[101][101]) {
    int visited[101], num = 0;
    queue<int> q;
    //�ش� ����ž�� �湮�ߴ��� ��Ÿ���� visited �ʱ�ȭ
    for (int a = 1; a <= n; a++) visited[a] = 0;
    //1�� ����ž�� ���� ��Ʈ��ũ ž��
    q.push(1);
    visited[1] = 1;
    //���� ��Ʈ��ũ�� ��� ����ž�� Ž���� ������ �ݺ�
    while (!q.empty()) {
        num++;
        for (int a = 1; a <= n; a++) {
            //���� ����ž�� ����Ǿ� ������ ���� �湮���� ���� ����ž�� ť�� �߰�
            if (connected[q.front()][a] == 1 && visited[a] == 0) {  
                q.push(a);
                visited[a] = 1;
            }
        }
        q.pop();
    }

    return max(n - (2 * num), (2 * num) - n);
}