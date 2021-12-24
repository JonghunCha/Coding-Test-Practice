/*
문제 링크 : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

DFS로 해결할 수 있는 문제다.

처음엔 queue를 이용하여 BFS로 해결하려 했으나, 계속해서 time limit exceed가 떠서, 단순 while문을 이용한 DFS로 해결하였다.

우선 왼쪽 자식의 next는 오른쪽 자식이 있는 경우 항상 오른쪽 자식이다. 그러나 오른쪽 자식이 없는 경우 next노드를 타고 이동하며 가장 가까운 노드를 찾으면 된다.

해당 부분을 구현한 것이 findnext함수다.

또한 현재 노드의 자식노드들의 next를 계산한 후에는 항상 오른쪽 자식을 먼저 탐색해야 한다.

이유는 findnext함수에서 next를 구하기 위해서 오른쪽으로 노드를 타고 이동하는데, 왼쪽부터 탐색하면 아직 계산되지 않은 next를 타게되기 때문이다.
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
        //왼쪽 자식의 경우
        if (root->left) {
            if (root->right) {  //오른쪽 자식이 있는 경우 해당 노드가 next가 된다
                root->left->next = root->right;
            }
            else {  //오른쪽 자식이 없는 경우 findnext를 통해 next를 찾는다
                root->left->next = findnext(root->next);
            }
        }

        if (root->right) {  //오른쪽 자식의 경우 항상 부모노드의 next를 타고 이동하며 next를 찾아야 한다
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
        return findnext(parent->next);  //현재 노드가 자식이 없는 경우 parent->next에서 찾아야한다
    }
};