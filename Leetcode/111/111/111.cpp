#include "stdafx.h"
#include <algorithm>
#include <queue>

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

	int minDepth(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q;

		q.push(root);
		int ret = 0;

		while (1) {
			ret++;
			TreeNode* cn;
			queue<TreeNode*> nq;
			while (!q.empty()) {
				cn = q.front();
				q.pop();

				if (!cn->left && !cn->right) {
					return ret;
				}
				if (cn->left) nq.push(cn->left);
				if (cn->right) nq.push(cn->right);
			}
			q.swap(nq);
		}

		return ret;
	}
};

int main()
{
    return 0;
}

