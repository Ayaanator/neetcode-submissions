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
    int minimum = -1e8;
    int maximum = 1e8;

    bool checkValid(TreeNode* node, int left, int right) {
        if(!node) return true;

        if(left < node->val && node->val < right) {
            return checkValid(node->left, left, node->val) && checkValid(node->right, node->val, right);
        } else {
            return false;
        }
        
    }
    
    bool isValidBST(TreeNode* root) {
        return checkValid(root, -1e9, 1e9);
    }
};
