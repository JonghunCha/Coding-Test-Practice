/*
���� ��ũ : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

DFS�� �ذ��� �� �ִ� ������.

ó���� queue�� �̿��Ͽ� BFS�� �ذ��Ϸ� ������, ����ؼ� time limit exceed�� ����, �ܼ� while���� �̿��� DFS�� �ذ��Ͽ���.

�켱 ���� �ڽ��� next�� ������ �ڽ��� �ִ� ��� �׻� ������ �ڽ��̴�. �׷��� ������ �ڽ��� ���� ��� next��带 Ÿ�� �̵��ϸ� ���� ����� ��带 ã���� �ȴ�.

�ش� �κ��� ������ ���� findnext�Լ���.

���� ���� ����� �ڽĳ����� next�� ����� �Ŀ��� �׻� ������ �ڽ��� ���� Ž���ؾ� �Ѵ�.

������ findnext�Լ����� next�� ���ϱ� ���ؼ� ���������� ��带 Ÿ�� �̵��ϴµ�, ���ʺ��� Ž���ϸ� ���� ������ ���� next�� Ÿ�ԵǱ� �����̴�.
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
        if (root == NULL)    return root;   
        //���� �ڽ��� ���
        if (root->left) {
            if (root->right) {  //������ �ڽ��� �ִ� ��� �ش� ��尡 next�� �ȴ�
                root->left->next = root->right;
            }
            else {  //������ �ڽ��� ���� ��� findnext�� ���� next�� ã�´�
                root->left->next = findnext(root->next);
            }
        }

        if (root->right) {  //������ �ڽ��� ��� �׻� �θ����� next�� Ÿ�� �̵��ϸ� next�� ã�ƾ� �Ѵ�
            root->right->next = findnext(root->next);
        }

        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* findnext(Node* parent) {
        if (parent == NULL)  return NULL;   
        if (parent->left)    return parent->left;
        if (parent->right)   return parent->right;
        return findnext(parent->next);  //���� ��尡 �ڽ��� ���� ��� parent->next���� ã�ƾ��Ѵ�
    }
};