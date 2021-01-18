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

	bool isSubtree_root(TreeNode* s, TreeNode* t){
		if (!s && !t) return true;
		if (!s || !t) return false;

		if (s->val == t->val){
			return isSubtree_root(s->left, t->left) && isSubtree_root(s->right, t->right);
		}

		return false;
	}

    bool isSubtree(TreeNode* s, TreeNode* t) {
    	if (!s) return false;
    	return isSubtree_root(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
