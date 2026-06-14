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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;

        TreeNode* smaller;
        TreeNode* bigger;

        TreeNode* r = root;
        TreeNode* l = root;

        if(!root) return nullptr;

        if(p->val > q->val) {
            bigger = p;
            smaller = q;
        } else {
            bigger = q;
            smaller = p;
        }

        while(r->val != bigger->val || l->val != smaller->val) {

            if(r->val <= bigger->val && l->val <= smaller->val) {
                if(r->val != bigger->val) r = r->right;
                if(l->val != smaller->val) l = l->right;
                if(l == r) lca = lca->right;
            } else if(r->val >= bigger->val && l->val >= smaller->val) {
                if(r->val != bigger->val) r = r->left;
                if(l->val != smaller->val) l = l->left;
                if(l == r) lca = lca->left;
            } else if(r->val < bigger->val && l->val > smaller->val) {
                return lca;
            }
        }

        return lca;
    }
};
