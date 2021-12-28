/*
문제 링크 : https://leetcode.com/problems/all-paths-from-source-to-target/
DFS로 해결할 수 있는 문제다.

DAG이기 때문에 순환에 대한 걱정을 할 필요가 없다.

따라서 0번 노드부터 DFS를 통해 이동할 수 있는 모든 경로를 고려하고 그 과정에 n-1번 노드에 도착한다면 정답에 추가하면 된다.
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
        path.push_back(node);   //현재 노드 path에 추가

        if (node == n - 1) {    //만약 현재 노드가 n-1번째 노드라면 지금까지의 path를 정답에 추가
            answer.push_back(path);
            path.pop_back();
            return;
        }

        for (int a = 0; a < graph[node].size(); a++) {  //현재 노드가 n-1번째가 아니라면 탐색을 진행한다
            DFS(graph, answer, path, graph[node][a]);
        }
        path.pop_back();    //다음 탐색을 위해 현재 노드 path에서 제거
        return;
    }
};