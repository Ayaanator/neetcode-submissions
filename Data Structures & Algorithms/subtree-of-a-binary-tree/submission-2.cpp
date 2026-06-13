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
    bool checkSame(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(root1 && root2 && root1->val == root2->val) return checkSame(root1->left, root2->left) && checkSame(root1->right, root2->right);
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!checkSame(root, subRoot)) return root && subRoot && (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        else return true;
    }
};
