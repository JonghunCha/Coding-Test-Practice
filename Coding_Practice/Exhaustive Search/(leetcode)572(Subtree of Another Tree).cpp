/*
문제 링크 : https://leetcode.com/problems/subtree-of-another-tree/
DFS로 해결할 수 있는 문제다.

우선 isSubtree함수에서 root노드와 subRoot노드의 val값을 비교했을 때 같다면 isSame함수를 호출해서 두 트리가 완전히 동일한지 확인한다.

만약 root노드와 subRoot노드의 val값이 다르다면 root의 왼쪽 자식과 오른쪽 자식에 대해서도 isSubtree함수를 호출한다.
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