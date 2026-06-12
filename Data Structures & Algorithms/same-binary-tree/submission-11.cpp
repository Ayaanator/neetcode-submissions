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
    int num1;
    int num2;
    bool flag = true;

    void dfs(TreeNode* root1, TreeNode* root2) {
        if((!root1 && root2) || (!root2 && root1)) flag = false;

        if(!root1) return;
        if(!root2) return;

        if(flag && (root1->val != root2->val)) {
            flag = false;
        }

        dfs(root1->right, root2->right);
        dfs(root1->left, root2->left);
        
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;

        if(p->val != q->val) return false;

        dfs(p->right, q->right);
        dfs(p->left, q->left);

        return flag;
    }
};
