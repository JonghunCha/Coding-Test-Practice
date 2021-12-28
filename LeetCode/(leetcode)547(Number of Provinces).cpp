/*
���� ��ũ : https://leetcode.com/problems/number-of-provinces/
DFS�� �ذ��� �� �ִ� ������.

ù �������� DFS�� ������ ������ ��� �� ���� province�� ���� ��Ų��.

�׷� ���� ���� ��� province���� ������ ���� ������ ã�� �� ������ �ݺ��Ѵ�.
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