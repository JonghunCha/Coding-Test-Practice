/*
���� ��ũ : https://leetcode.com/problems/all-paths-from-source-to-target/
DFS�� �ذ��� �� �ִ� ������.

DAG�̱� ������ ��ȯ�� ���� ������ �� �ʿ䰡 ����.

���� 0�� ������ DFS�� ���� �̵��� �� �ִ� ��� ��θ� ����ϰ� �� ������ n-1�� ��忡 �����Ѵٸ� ���信 �߰��ϸ� �ȴ�.
*/
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answer;
        vector<int> path;

        DFS(graph, answer, path, 0);

        return answer;
    }

    void DFS(vector<vector<int>>& graph, vector<vector<int>>& answer, vector<int>& path, int node) {
        int n = graph.size();
        path.push_back(node);   //���� ��� path�� �߰�

        if (node == n - 1) {    //���� ���� ��尡 n-1��° ����� ���ݱ����� path�� ���信 �߰�
            answer.push_back(path);
            path.pop_back();
            return;
        }

        for (int a = 0; a < graph[node].size(); a++) {  //���� ��尡 n-1��°�� �ƴ϶�� Ž���� �����Ѵ�
            DFS(graph, answer, path, graph[node][a]);
        }
        path.pop_back();    //���� Ž���� ���� ���� ��� path���� ����
        return;
    }
};