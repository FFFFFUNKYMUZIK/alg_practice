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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret;

        if (!root) return 0;

        if (root->val < low) ret = rangeSumBST(root->right, low, high);
        else if (root->val > high) ret = rangeSumBST(root->left, low, high);
        else ret = root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);

    	return ret;
    }
};