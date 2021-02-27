/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
*/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

    	using tn = struct {
    		TreeNode *p;
    		int idx;
    	};

    	stack<tn> st;

    	st.push({root, 0});
    	vector<TreeNode *> path(501, nullptr);
    	int pathlen;

    	tn cur;
        while(!st.empty()){
        	cur = st.top();
        	st.pop();
        	pathlen = cur.idx + 1;
        	path[cur.idx] = cur.p;

        	if (cur.p == target){
        		break;
        	}

        	if (cur.p->right) st.push({cur.p->right, cur.idx + 1});
        	if (cur.p->left) st.push({cur.p->left, cur.idx + 1});
        }

        vector<int> ret;

        stack<tn>().swap(st);
        st.push({target, 0});

        auto getKth = [](stack<tn> &st, int K, vector<int> &ret)->void{
	        tn cur;
	        while(!st.empty()){
	        	cur = st.top();
	        	st.pop();
	        	if (cur.idx == K){
	        		ret.push_back(cur.p->val);
	        	}
	        	else if (cur.idx > K){
	        		continue;
	        	}

	        	if (cur.p->right) st.push({cur.p->right, cur.idx + 1});
	        	if (cur.p->left) st.push({cur.p->left, cur.idx + 1});	
	        }
    	};
    	getKth(st, K, ret);

		TreeNode* cn;
        K = K - 1;
        for (int i=pathlen-2;i>=0 && K>=0;i--){
        	cn = path[i];
        	if (K>0){
        		stack<tn> st;
        		
        		if (path[i+1] == path[i]->left && cn->right != NULL){
        			st.push({cn->right, 0});
        			getKth(st, K-1, ret);
        		}
        		else if (path[i+1] == path[i]->right && cn->left != NULL){
        			st.push({cn->left, 0});
        			getKth(st, K-1, ret);
        		}
        	}
        	else if (K==0){
        		ret.push_back(cn->val);
        	}
        	K--;
        }

        return ret;
    }
};
