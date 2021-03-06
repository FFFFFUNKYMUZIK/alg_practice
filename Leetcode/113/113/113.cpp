#include "stdafx.h"
#include <vector>

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
	vector<vector<int>> ret;
public:

	void traverse(TreeNode* root, vector<int> & bucket, int sum) {
		int nsum = sum - root->val;
		bucket.push_back(root->val);
		if (!root->left && !root->right) {
			if (nsum == 0) ret.push_back(bucket);
			bucket.pop_back();
			return;
		}
		if (root->left) traverse(root->left, bucket, nsum);
		if (root->right) traverse(root->right, bucket, nsum);
		bucket.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>>().swap(ret);
		if (!root) return ret;

		vector<int> bucket;
		traverse(root, bucket, sum);
		
		return ret;
	}
};

int main()
{
    return 0;
}

