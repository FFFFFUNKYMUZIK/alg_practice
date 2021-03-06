#include "stdafx.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return (sum==0);
		bool ret = false;
		int nsum = sum - root->val;
		if (!root->left && !root->right) return (nsum == 0);
		
		if (root->left) ret = hasPathSum(root->left, nsum);
		if (root->right && !ret) ret = hasPathSum(root->right, nsum);

		return ret;
	}
};

int main()
{
    return 0;
}

