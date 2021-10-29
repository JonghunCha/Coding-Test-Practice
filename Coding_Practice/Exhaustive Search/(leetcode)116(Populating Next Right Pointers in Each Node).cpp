/*
���� ��ũ : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
DFS�� �ذ��� �� �ִ� ������.

���ʺ��� DFS�� Ž���� �ϸ� next�����͸� �������ָ� �ȴ�.

�� ���� ������ ���� ���� ������ ������ ����� next�� NULL�� �Ǿ�� �ϴµ� �̸� ���� �ش� ��尡 ������ ������� �ƴ����� ��Ÿ���� bool�Ű������� �ϳ� �ξ���.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)    return NULL;
        root->next = NULL;
        DFS(root, true);
        return root;
    }

    void DFS(Node* parent, bool last) {
        if (parent->left == NULL)    return;    //�� �̻� ������ ��尡 ���� ���
        parent->left->next = parent->right;     //���� �ڽ��� next�� �׻� ������ �ڽ�
        if (last)    parent->right->next = NULL;    //���� parent�� ������ ����� ��� ������ �ڽ��� next�� NULL
        else    parent->right->next = parent->next->left;   //������ ��尡 �ƴ� ��� ������ �ڽ��� next�� �θ� ����� next�� ���� �ڽ�

        DFS(parent->left, false);   //���� �ڽĿ� ���� DFS ����
        DFS(parent->right, last);   //������ �ڽĿ� ���� DFS ����
    }
};