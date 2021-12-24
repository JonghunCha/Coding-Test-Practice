/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/87946
���� Ž������ �ذ��� �� �ִ� ������.(��� ������ȸ ����� ��찡 8! = 40320 �̱⿡ �ð������� ���)

�� �ڵ��� ��� DFS�� �̿��Ͽ� ������ ���� ��� ���տ� ���� �׽�Ʈ�ϰ� ���� ���� ������ ���� ��츦 answer������ �����Ͽ���.
*/
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int k, vector<vector<int>>& dungeons, int order[8], int decided_num);

int solution(int k, vector<vector<int>> dungeons) {
    int order[8];   //order[a]���� a�� ������ �� ��°�� �湮�Ǵ��� ����

    for (int a = 0; a < dungeons.size(); a++)    order[a] = -1;
    DFS(k, dungeons, order, 0);

    return answer;
}

void DFS(int k, vector<vector<int>>& dungeons, int order[8], int decided_num) {
    if (decided_num == dungeons.size()) {   //��� ������ ������ ���� ���
        int num = 0, curr_k = k;
        bool can_continue = true;

        for (int a = 0; a < dungeons.size(); a++) {
            for (int b = 0; b < dungeons.size(); b++) {
                if (order[b] == a) {    //b��° ������ a��°�� �湮�Ǵ� ���
                    if (dungeons[b][0] <= curr_k) { //���� ���� ���� �Ƿε��� �ּ� �ʿ� �Ƿε����� ũ�ٸ� ������ �湮
                        curr_k -= dungeons[b][1];
                        num++;
                    }
                    else {  //�׷��� ���� ��� can_continue�� false�� ����
                        can_continue = false;
                    }
                    break;
                }
            }
            if (!can_continue)   break; //���� ���� ������ ���� ���� ��� for�� ����
        }
        //answer�� �ִ밪���� ����
        if (num > answer)    answer = num;
    }

    for (int a = 0; a < dungeons.size(); a++) { //���� �� ��°�� �湮���� �������� ���� ������ �湮 ���� ����
        if (order[a] == -1) {
            order[a] = decided_num;
            DFS(k, dungeons, order, decided_num + 1);
            order[a] = -1;
        }
    }
}