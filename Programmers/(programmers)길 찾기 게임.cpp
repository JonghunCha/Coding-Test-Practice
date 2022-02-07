/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42892
Ʈ���� �����ϰ� �ܼ��� ���� ��ȸ, ���� ��ȸ�� ����� �����ϸ� �ȴ�.

Ʈ���� �����ϱ� ���� �� ��带 �ǹ��ϴ� treeŬ������ �����Ͽ���.

treeŬ�������� ����, ������ �ڽ��� ����ȣ�� �����ϴ� ����, �θ� ����ȣ�� �����ϴ� ����, �ش� ����� x��ǥ�� �����ϴ� ������ �̷���� �ִ�.

nodeinfo�� y�� ������������ �����Ͽ� ��Ʈ ��带 ã�Ƴ� ��, ��� ��带 ��Ʈ���� �����Ͽ� ���� Ʈ�� ���¸� �����ϵ��� �������ش�.

�׷� ���� ���� ��ȸ, ���� ��ȸ�� ����� �����Ͽ���.
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
void maketree(tree trees[10001], int root, vector<vector<int>>& nodeinfo);  //Ʈ���� �����ϴ� �Լ�
void preorder(vector<int>& pre, tree trees[10001], int nodenum);    //���� ��ȸ�� ����� pre�� ��� �Լ�
void postorder(vector<int>& post, tree trees[10001], int nodenum);  //���� ��ȸ�� ����� post�� ��� �Լ�

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> pre, post;
    tree trees[10001];
    int root, curr;
    bool is_inserted;
    //nodeinfo�� �� ����� ��ȣ������ �߰�
    for (int a = 0; a < nodeinfo.size(); a++)    nodeinfo[a].push_back(a + 1);
    //nodeinfo�� y�� ��������, y�� ���ٸ� x�� ������������ ����
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    //Ʈ���� ����
    for (int a = 0; a < nodeinfo.size(); a++)    trees[nodeinfo[a][2]].x = nodeinfo[a][0];
    root = nodeinfo[0][2];
    trees[root].parent = 0;
    maketree(trees, root, nodeinfo);
    //����, ���� ��ȸ ��� ����
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
    //nodeinfo�� y�� ������������, y�� ���ٸ� x�� ������������ ���ĵǾ� �ִ�.
    //���� �� ��带 ��Ʈ���� �����ؼ� �ϳ��� �������ָ� ����Ʈ���� �ϼ��� �� �ִ�.
    for (int a = 1; a < nodeinfo.size(); a++) {
        curr = root;
        is_inserted = false;
        while (1) {
            if (nodeinfo[a][0] < trees[curr].x) {   //������ ��尡 ���� ��ġ�� ��庸�� ���ʿ� ��ġ�ؾ��� ���
                if (trees[curr].leftchild == 0) {   //���� �ڽ� �ڸ��� ��������� �� ���� ����
                    trees[curr].leftchild = nodeinfo[a][2];
                    trees[nodeinfo[a][2]].parent = curr;
                    is_inserted = true;
                }
                else {  //���� �ڽ� �ڸ��� ������� �ʴٸ� ���� �ڽĹ������� ������ �ڸ��� ��� Ž��
                    curr = trees[curr].leftchild;
                }
            }
            else {  //���� �ݴ��� ���(������ �ڽ����� ����)
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