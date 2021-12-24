/*
문제 링크 : https://leetcode.com/problems/number-of-provinces/
DFS로 해결할 수 있는 문제다.

첫 지역부터 DFS로 인접한 구역을 모두 한 개의 province에 포함 시킨다.

그런 다음 아직 어느 province에도 속하지 못한 지역을 찾고 위 과정을 반복한다.
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), province_num = 0;
        int* province = new int[n], * visited = new int[n];
        for (int a = 0; a < n; a++) {
            province[a] = 0;
            visited[a] = 0;
        }
        for (int a = 0; a < n; a++)  cout << province[a] << ' ';
        for (int a = 0; a < n; a++) {
            if (province[a] == 0 && visited[a] == 0) {
                Search_Province(isConnected, a, province, visited, ++province_num);
            }
        }
        delete[]province;
        return province_num;
    }

    void Search_Province(vector<vector<int>>& isConnected, int index, int* province, int* visited, int province_num) {
        province[index] = province_num;
        visited[index] = 1;
        for (int a = 0; a < isConnected.size(); a++) {
            if (visited[a] == 0 && isConnected[index][a] == 1 && a != index)    Search_Province(isConnected, a, province, visited, province_num);
        }
    }
};