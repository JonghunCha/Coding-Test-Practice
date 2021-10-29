/*
문제 링크 : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
DFS로 해결할 수 있는 문제다.

왼쪽부터 DFS로 탐색을 하며 next포인터를 지정해주면 된다.

한 가지 주의할 점은 같은 레벨의 마지막 노드의 next는 NULL이 되어야 하는데 이를 위해 해당 노드가 마지막 노드인지 아닌지를 나타내는 bool매개변수를 하나 두었다.
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
        if (parent->left == NULL)    return;    //더 이상 진행할 노드가 없는 경우
        parent->left->next = parent->right;     //왼쪽 자식의 next는 항상 오른쪽 자식
        if (last)    parent->right->next = NULL;    //만약 parent가 마지막 노드인 경우 오른쪽 자식의 next는 NULL
        else    parent->right->next = parent->next->left;   //마지막 노드가 아닌 경우 오른쪽 자식의 next는 부모 노드의 next의 왼쪽 자식

        DFS(parent->left, false);   //왼쪽 자식에 대해 DFS 진행
        DFS(parent->right, last);   //오른쪽 자식에 대해 DFS 진행
    }
};