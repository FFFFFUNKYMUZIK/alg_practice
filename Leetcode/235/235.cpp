/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rval = root->val;

        if (p->val < rval && q->val < rval) return lowestCommonAncestor(root->left, p, q);
        if (p->val > rval&& q->val > rval) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};