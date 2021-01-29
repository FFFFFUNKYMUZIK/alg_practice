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

	int pathSum_helper(unordered_map<int, int>& hash, TreeNode* cur, int cur_sum, int sum){

    	cur_sum += cur->val;
    	int ret;

    	ret = hash[cur_sum - sum];
	   	hash[cur_sum]++;
    		
    	if (cur->left) ret += pathSum_helper(hash, cur->left, cur_sum, sum);
		if (cur->right) ret += pathSum_helper(hash, cur->right, cur_sum, sum);

    	hash[cur_sum]--;

    	return ret;
	}


public:
    int pathSum(TreeNode* root, int sum) {
    	if(!root) return 0;

    	unordered_map<int, int> hash;
    	hash[0] = 1;

    	return pathSum_helper(hash, root, 0, sum);
    }
};