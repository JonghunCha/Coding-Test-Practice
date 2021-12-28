/*
���� ��ũ : https://leetcode.com/problems/subtree-of-another-tree/
DFS�� �ذ��� �� �ִ� ������.

�켱 isSubtree�Լ����� root���� subRoot����� val���� ������ �� ���ٸ� isSame�Լ��� ȣ���ؼ� �� Ʈ���� ������ �������� Ȯ���Ѵ�.

���� root���� subRoot����� val���� �ٸ��ٸ� root�� ���� �ڽİ� ������ �ڽĿ� ���ؼ��� isSubtree�Լ��� ȣ���Ѵ�.
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root->val == subRoot->val && isSame(root, subRoot))  return true;
        if (root->left && isSubtree(root->left, subRoot))    return true;
        if (root->right && isSubtree(root->right, subRoot))  return true;
        return false;
    }

    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)  return true;
        else if (root1 != NULL && root2 == NULL) return false;
        else if (root1 == NULL && root2 != NULL) return false;
        else {
            if (root1->val == root2->val) {
                return (isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
            }
            else    return false;
        }
    }
};