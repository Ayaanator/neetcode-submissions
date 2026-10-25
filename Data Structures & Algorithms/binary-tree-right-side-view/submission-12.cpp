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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> lst;

            for(int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                lst.push_back(t->val);
                q.pop();

                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);
            }

            res.push_back(lst[0]);
        }

        return res;
    }
};
