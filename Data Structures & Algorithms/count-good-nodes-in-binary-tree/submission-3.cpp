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
    int ctr = 0;
    int mx = -1e8;

    void checkThree(TreeNode* root, int l_mx) {
        if(!root) return;
        int local_max = max(root->val, l_mx);
        if(root->val >= l_mx) ctr++;

        checkThree(root->left, local_max);
        checkThree(root->right, local_max);
    }

    int goodNodes(TreeNode* root) {
        checkThree(root, root->val);
        return ctr;
    }
};
