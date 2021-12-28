/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/43162
DFS�� �ذ��� �� �ִ� ������.

0�� ��ǻ�� n-1�� ��ǻ�ͱ��� �ݺ��ϸ� ���� ��Ʈ��ũ�� ������ ���� ��ǻ�͸� ����.

�׷� ���� �ش� ��ǻ�Ϳ� ����� ��ǻ�͸� ��Ʈ��ũ�� �߰���Ų��.

����� ��ǻ�Ϳ� ���ؼ��� ���� ������ �ݺ��Ѵ�.
*/
#include <string>
#include <vector>

using namespace std;

void searchNetwork(int n, vector<vector<int>>& computers, int idx, int network[200], int network_num);

int solution(int n, vector<vector<int>> computers) {
    int network[200], network_num = 0;
    //network[a]�� a�� ��ǻ�Ͱ� �� ��° ��Ʈ��ũ�� ���ߴ����� �ǹ�(�ʱⰪ�� 0)
    for (int a = 0; a < n; a++)   network[a] = 0;
    for (int a = 0; a < n; a++) {
        if (network[a] == 0) {  //���� ��� ��Ʈ��ũ���� ������ ���� ��ǻ�Ϳ� ���� ���ο� ��Ʈ��ũ ��ȣ�� �Ҵ��ϰ� ����� ��� ��ǻ�͸� �ش� ��Ʈ��ũ�� �߰�
            network[a] = ++network_num;
            searchNetwork(n, computers, a, network, network_num);
        }
    }

    return network_num;
}
//idx�� �ش��ϴ� ��ǻ�Ϳ� ����� ��ǻ�� �� ��𿡵� ������ ���� ��ǻ�͸� ���� network_num�� �߰�
void searchNetwork(int n, vector<vector<int>>& computers, int idx, int network[200], int network_num) {
    for (int a = 0; a < n; a++) {
        if (network[a] == 0 && computers[idx][a] == 1) {
            network[a] = network_num;
            searchNetwork(n, computers, a, network, network_num);
        }
    }
}