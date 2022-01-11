/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/68936
ť�� �̿��Ͽ� �ذ��� ������.

�켱 arr��ü ������ ť�� �ִ´�.(ť�� arr �� ��ü�� �ִ� ���� �ƴ� arr�� ���� �� ����, ������ �Ʒ� ������ ��ǥ�� ����)

�׷� ���� �Ʒ� ������ ť�� ����ְ� �� ������ �ݺ��Ѵ�.

1. ť�� front���� Ư�� ���� S�� ����
	1-1. �ش� ������ ���� ���� ����� ī�����ϰ� while�ݺ�
	1-2. �ش� ������ ���� ���� ���� �ƴ϶�� 4�������� ���� ��ǥ�� �ٽ� ť�� push()
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

    q.push(make_tuple(0, 0, len - 1, len - 1)); //��ü ������ ť�� push
    while (!q.empty()) {
        x1 = get<0>(q.front());
        y1 = get<1>(q.front());
        x2 = get<2>(q.front());
        y2 = get<3>(q.front());
        q.pop();

        if (isAllsame(arr, x1, y1, x2, y2)) {   //���� ���� ������ ��� ���� ���ڶ�� �ش� ���ڿ� �´� ī��Ʈ�� ++
            if (arr[x1][y1] == 0)    zero_num++;
            else    one_num++;
        }
        else {  //���� ���� ������ ��� ���� ���ڰ� �ƴ� ���
            if (x2 - x1 == 1) { //���� ������ 2*2�� ��� 4���� �������� �� �� �̻� ���� ���� �����Ƿ� �ٷ� ī����
                for (int a = x1; a <= x2; a++) {
                    for (int b = y1; b <= y2; b++) {
                        if (arr[a][b] == 0)  zero_num++;
                        else    one_num++;
                    }
                }
            }
            else {  //4�� ������ ť�� push
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
//(x1, y1)��ǥ���� (x2, y2)��ǥ������ ������ ��� ���� �������� Ȯ���ϴ� �Լ�
bool isAllsame(vector<vector<int>>& arr, int x1, int y1, int x2, int y2) {
    int temp = arr[x1][y1];

    for (int a = x1; a <= x2; a++) {
        for (int b = y1; b <= y2; b++) {
            if (arr[a][b] != temp)   return false;
        }
    }

    return true;
}