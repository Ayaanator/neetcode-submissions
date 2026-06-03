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
    int findDepth(TreeNode* root, int n) {
        if(root == nullptr) return n;
        else return max(findDepth(root->left, n + 1), findDepth(root->right, n + 1));
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(findDepth(root->left, 1), findDepth(root->right, 1));
    }
};
