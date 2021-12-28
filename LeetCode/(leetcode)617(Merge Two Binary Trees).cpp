/*
���� ��ũ : https://leetcode.com/problems/merge-two-binary-trees/
DFS�� �ذ��� �� �ִ� ������.

tree1�� tree2�� ��ġ�� �������� �ذ��Ͽ���.
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
        if (root1 == NULL && root2 == NULL)  return NULL;   //ó������ �Ѵ� �� Ʈ���� ���
        else if (root1 == NULL)  return root2;  //�� �� �ϳ��� �� Ʈ���� ���
        else if (root2 == NULL)  return root1;  //�� �� �ϳ��� �� Ʈ���� ���
        //�� �� �� Ʈ���� �ƴ� ���
        root1->val += root2->val;
        DFS(root1, root2);
        return root1;
    }

    void DFS(TreeNode* tree1, TreeNode* tree2) {
        TreeNode* new_node;
        //���ʺ��� DFS ����(�� Ʈ�� ��� ���� �ڽ��� �ְų� tree2���� �����ڽ��� �ִ� ��츸 DFS�� �����Ѵ�)
        if (tree1->left != NULL && tree2->left != NULL) {
            tree1->left->val += tree2->left->val;
            DFS(tree1->left, tree2->left);
        }
        else if (tree1->left == NULL && tree2->left != NULL) {
            new_node = new TreeNode(tree2->left->val);
            tree1->left = new_node;
            DFS(tree1->left, tree2->left);
        }
        //������ DFS ����(�� Ʈ�� ��� ������ �ڽ��� �ְų� tree2���� �����ڽ��� �ִ� ��츸 DFS�� �����Ѵ�)
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