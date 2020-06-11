#include <iostream>
#include <vector>
#include <queue>


//Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
	vector<int> ret;
	if (!root) return ret;

	queue<TreeNode*> layer;
	layer.push(root);

	while(!layer.empty()){
		queue<TreeNode*> tmp;
		ret.push_back(layer.front()->val);
		
		while(!layer.empty()){
			TreeNode* cur = layer.front();
			layer.pop();
			
			if (cur->right) tmp.push(cur->right);
			if (cur->left) tmp.push(cur->left);
		}
		layer.swap(tmp);
	}

	return ret;
    }
};


int main(){
	Solution sol;


	return 0;
}
