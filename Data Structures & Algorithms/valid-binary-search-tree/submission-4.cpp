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
    bool checkValid(TreeNode* node, long long left, long long right) {
        if(!node) return true;

        if(left < node->val && node->val < right) {
            return checkValid(node->left, left, node->val) && checkValid(node->right, node->val, right);
        } else {
            return false;
        }
        
    }
    
    bool isValidBST(TreeNode* root) {
        return checkValid(root, -1e13, 1e13);
    }
};
