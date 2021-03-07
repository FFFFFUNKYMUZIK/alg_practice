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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        using el = struct{
        	TreeNode* pn;
        	int maxval;
        };

        stack<el> st;

        st.push({root, root->val - 1});

        int cnt = 0;
        while(!st.empty()){
        	el cur = st.top();
        	st.pop();

        	if (cur.pn->val >= cur.maxval){
        		cnt++;
        		if (cur.pn->left)
        			st.push({cur.pn->left, cur.pn->val});
        		if (cur.pn->right)
        			st.push({cur.pn->right, cur.pn->val});
        	}
        	else{
        		if (cur.pn->left)
        			st.push({cur.pn->left, cur.maxval});
        		if (cur.pn->right)
        			st.push({cur.pn->right, cur.maxval});	
        	}
        }

        return cnt;
    }
};