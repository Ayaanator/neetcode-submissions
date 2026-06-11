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
    bool flag = true;
    int dfs(TreeNode* root, int num) {
        if(!root) return num;
        int l = dfs(root->left, num + 1);
        int r = dfs(root->right, num + 1);
        int res = max(r, l);
        if((abs(l - r) <= 1) == false) flag = false;
        return res;
   }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = dfs(root->left, 1);
        int r = dfs(root->right, 1);
        if((abs(l - r) <= 1) == false) flag = false;
        return flag;
    }
};
