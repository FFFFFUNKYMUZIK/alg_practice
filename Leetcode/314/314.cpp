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
/*
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


class Solution {

	#define MAX_NODE (100)

public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
    	vector<vector<int>> ret;
    	if (!root) return ret;

    	/* index : 0 ~ MAX_NODE*2 - 2 */
    	/* index of zero vertical order : MAX_NODE - 1 */
    	int offset = MAX_NODE - 1;
        vector<vector<int>> bucket(MAX_NODE * 2 - 1, vector<int>());

        using node = struct {int vo; TreeNode* p;};

        queue<node> q;
        q.push({0, root});

        node cur;
        while(!q.empty()){
        	cur = q.front();
        	q.pop();

        	bucket[offset + cur.vo].push_back(cur.p->val);
        	
			if (cur.p->left) q.push({cur.vo - 1, cur.p->left});
        	if (cur.p->right) q.push({cur.vo + 1, cur.p->right});
        	
        }

        for (int i=0;i<bucket.size();i++){
        	if (bucket[i].size() > 0){
				ret.push_back(bucket[i]);
			}       	
        }

        return ret;
    }
};