#include "stdafx.h"
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/
class BSTIterator {

	stack<pair<TreeNode*, int>> nodest;

public:
	BSTIterator(TreeNode* root) {
		if (!root) return;
		nodest.push(make_pair(root, 0));
	}

	/** @return the next smallest number */
	int next() {

		TreeNode* cur;
		int turn = 0;
		while(!nodest.empty()) {
			cur = nodest.top().first;
			turn = nodest.top().second;
			nodest.pop();

			if (turn == 1) return cur->val;
			else {
				if (cur->right) nodest.push(make_pair(cur->right, 0));
				nodest.push(make_pair(cur, 1));
				if (cur->left) nodest.push(make_pair(cur->left, 0));
			}
		}

		return -1;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return (!nodest.empty());
	}
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

int main()
{
    return 0;
}

