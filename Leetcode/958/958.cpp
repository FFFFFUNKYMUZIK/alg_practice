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
    bool isCompleteTree(TreeNode* root) {

    	using node = struct {
    		int i;
    		TreeNode* pn;
    	};

    	queue<node> q;
    	
    	int seq = 1;
    	q.push({seq, root});
    	node c;

    	while (!q.empty()){
    		queue<node> next_q;

    		while (!q.empty()){
    			c = q.front();
    			q.pop();
    			if (c.i != seq){
    				return false;
    			}

    			if (c.pn->left != nullptr) next_q.push({2*seq, c.pn->left});
    			if (c.pn->right != nullptr) next_q.push({2*seq + 1, c.pn->right});
    			seq++;
    		}

    		q.swap(next_q);
    	}

    	return true;
    }
};
