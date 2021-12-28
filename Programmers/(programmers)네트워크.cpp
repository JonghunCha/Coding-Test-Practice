/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43162
DFS로 해결할 수 있는 문제다.

0번 컴퓨터 n-1번 컴퓨터까지 반복하며 아직 네트워크에 속하지 않은 컴퓨터를 고른다.

그런 다음 해당 컴퓨터와 연결된 컴퓨터를 네트워크에 추가시킨다.

연결된 컴퓨터에 대해서도 위의 과정을 반복한다.
*/
#include <string>
#include <vector>

using namespace std;

void searchNetwork(int n, vector<vector<int>>& computers, int idx, int network[200], int network_num);

int solution(int n, vector<vector<int>> computers) {
    int network[200], network_num = 0;
    //network[a]는 a번 컴퓨터가 몇 번째 네트워크에 속했는지를 의미(초기값은 0)
    for (int a = 0; a < n; a++)   network[a] = 0;
    for (int a = 0; a < n; a++) {
        if (network[a] == 0) {  //아직 어느 네트워크에도 속하지 않은 컴퓨터에 대해 새로운 네트워크 번호를 할당하고 연결된 모든 컴퓨터를 해당 네트워크에 추가
            network[a] = ++network_num;
            searchNetwork(n, computers, a, network, network_num);
        }
    }

    return network_num;
}
//idx에 해당하는 컴퓨터와 연결된 컴퓨터 중 어디에도 속하지 않은 컴퓨터를 같은 network_num에 추가
void searchNetwork(int n, vector<vector<int>>& computers, int idx, int network[200], int network_num) {
    for (int a = 0; a < n; a++) {
        if (network[a] == 0 && computers[idx][a] == 1) {
            network[a] = network_num;
            searchNetwork(n, computers, a, network, network_num);
        }
    }
}