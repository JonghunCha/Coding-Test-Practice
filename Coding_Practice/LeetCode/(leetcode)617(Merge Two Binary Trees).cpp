/*
문제 링크 : https://leetcode.com/problems/merge-two-binary-trees/
DFS로 해결할 수 있는 문제다.

tree1에 tree2를 합치는 방향으로 해결하였다.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)  return NULL;   //처음부터 둘다 빈 트리일 경우
        else if (root1 == NULL)  return root2;  //둘 중 하나가 빈 트리일 경우
        else if (root2 == NULL)  return root1;  //둘 중 하나가 빈 트리일 경우
        //둘 다 빈 트리가 아닌 경우
        root1->val += root2->val;
        DFS(root1, root2);
        return root1;
    }

    void DFS(TreeNode* tree1, TreeNode* tree2) {
        TreeNode* new_node;
        //왼쪽부터 DFS 진행(두 트리 모두 왼쪽 자식이 있거나 tree2에만 왼쪽자식이 있는 경우만 DFS를 진행한다)
        if (tree1->left != NULL && tree2->left != NULL) {
            tree1->left->val += tree2->left->val;
            DFS(tree1->left, tree2->left);
        }
        else if (tree1->left == NULL && tree2->left != NULL) {
            new_node = new TreeNode(tree2->left->val);
            tree1->left = new_node;
            DFS(tree1->left, tree2->left);
        }
        //오른쪽 DFS 진행(두 트리 모두 오른쪽 자식이 있거나 tree2에만 왼쪽자식이 있는 경우만 DFS를 진행한다)
        if (tree1->right != NULL && tree2->right != NULL) {
            tree1->right->val += tree2->right->val;
            DFS(tree1->right, tree2->right);
        }
        else if (tree1->right == NULL && tree2->right != NULL) {
            new_node = new TreeNode(tree2->right->val);
            tree1->right = new_node;
            DFS(tree1->right, tree2->right);
        }
    }
};