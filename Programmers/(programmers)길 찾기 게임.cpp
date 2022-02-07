/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42892
트리를 구성하고 단순히 전위 순회, 후위 순회의 결과를 추출하면 된다.

트리를 구성하기 위해 각 노드를 의미하는 tree클래스를 정의하였다.

tree클래스에는 왼쪽, 오른쪽 자식의 노드번호를 저장하는 변수, 부모 노드번호를 저장하는 변수, 해당 노드의 x좌표를 저장하는 변수로 이루어져 있다.

nodeinfo를 y의 내림차순으로 정렬하여 루트 노드를 찾아낸 뒤, 모든 노드를 루트에서 시작하여 이진 트리 형태를 구성하도록 연결해준다.

그런 다음 전위 순회, 후위 순회의 결과를 추출하였다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class tree {
public:
    int leftchild;
    int rightchild;
    int parent;
    int x;

    tree() {
        leftchild = 0;
        rightchild = 0;
        parent = 0;
        x = -1;
    }
};

bool compare(const vector<int>& v1, const vector<int>& v2);
void maketree(tree trees[10001], int root, vector<vector<int>>& nodeinfo);  //트리를 구성하는 함수
void preorder(vector<int>& pre, tree trees[10001], int nodenum);    //전위 순회의 결과를 pre에 담는 함수
void postorder(vector<int>& post, tree trees[10001], int nodenum);  //후위 순회의 결과를 post에 담는 함수

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> pre, post;
    tree trees[10001];
    int root, curr;
    bool is_inserted;
    //nodeinfo에 각 노드의 번호정보를 추가
    for (int a = 0; a < nodeinfo.size(); a++)    nodeinfo[a].push_back(a + 1);
    //nodeinfo를 y의 내림차순, y가 같다면 x의 오름차순으로 정렬
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    //트리를 형성
    for (int a = 0; a < nodeinfo.size(); a++)    trees[nodeinfo[a][2]].x = nodeinfo[a][0];
    root = nodeinfo[0][2];
    trees[root].parent = 0;
    maketree(trees, root, nodeinfo);
    //전위, 후위 순회 결과 추출
    preorder(pre, trees, root);
    postorder(post, trees, root);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

bool compare(const vector<int>& v1, const vector<int>& v2) {
    if (v1[1] == v2[1])  return v1[0] < v2[0];
    return v1[1] > v2[1];
}

void maketree(tree trees[10001], int root, vector<vector<int>>& nodeinfo) {
    int curr;
    bool is_inserted;
    //nodeinfo는 y의 내림차순으로, y가 같다면 x의 오름차순으로 정렬되어 있다.
    //따라서 각 노드를 루트에서 시작해서 하나씩 연결해주면 이진트리를 완성할 수 있다.
    for (int a = 1; a < nodeinfo.size(); a++) {
        curr = root;
        is_inserted = false;
        while (1) {
            if (nodeinfo[a][0] < trees[curr].x) {   //삽입할 노드가 현재 위치의 노드보다 왼쪽에 위치해야할 경우
                if (trees[curr].leftchild == 0) {   //왼쪽 자식 자리가 비어있으면 그 곳에 삽입
                    trees[curr].leftchild = nodeinfo[a][2];
                    trees[nodeinfo[a][2]].parent = curr;
                    is_inserted = true;
                }
                else {  //왼쪽 자식 자리가 비어있지 않다면 왼쪽 자식방향으로 삽입할 자리를 계속 탐색
                    curr = trees[curr].leftchild;
                }
            }
            else {  //위와 반대의 경우(오른쪽 자식으로 진행)
                if (trees[curr].rightchild == 0) {
                    trees[curr].rightchild = nodeinfo[a][2];
                    trees[nodeinfo[a][2]].parent = curr;
                    is_inserted = true;
                }
                else {
                    curr = trees[curr].rightchild;
                }
            }

            if (is_inserted) break;
        }
    }
}

void preorder(vector<int>& pre, tree trees[10001], int nodenum) {
    pre.push_back(nodenum);
    if (trees[nodenum].leftchild > 0)    preorder(pre, trees, trees[nodenum].leftchild);
    if (trees[nodenum].rightchild > 0)    preorder(pre, trees, trees[nodenum].rightchild);
}

void postorder(vector<int>& post, tree trees[10001], int nodenum) {
    if (trees[nodenum].leftchild > 0)    postorder(post, trees, trees[nodenum].leftchild);
    if (trees[nodenum].rightchild > 0)    postorder(post, trees, trees[nodenum].rightchild);
    post.push_back(nodenum);
}