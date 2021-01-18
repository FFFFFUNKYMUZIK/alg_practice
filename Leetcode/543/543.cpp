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
	int maxd;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root){
        	maxd = -1;
        	return 0;
        }

        int ldepth, ldiam;
        int rdepth, rdiam;

        ldiam = diameterOfBinaryTree(root->left);
        ldepth = maxd;

        rdiam = diameterOfBinaryTree(root->right);
        rdepth = maxd;

        maxd = max(ldepth, rdepth) + 1;

        return max(ldepth + rdepth + 2,max(ldiam, rdiam));
    }
};