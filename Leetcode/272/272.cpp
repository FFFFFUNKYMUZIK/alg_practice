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

    typedef struct node_t {
        int visit;
        TreeNode* pn;
    } node;

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        /* inorder traverse? */

        stack<node> st;
        st.push({0, root});

        TreeNode* cur;
        int visit;
        vector<int> sorted;
        int tarpos = -1;

        while(!st.empty()){
            cur = st.top().pn;
            visit = st.top().visit;
            st.pop();

            if (visit == 0){
                if (cur->right) st.push({0, cur->right});
                st.push({1, cur});
                if (cur->left) st.push({0, cur->left});
            }
            else{
                sorted.push_back(cur->val);
                if ( cur->val > target && tarpos == -1) tarpos = sorted.size() - 1;
            }
        }

        int n = sorted.size();
        if (tarpos == -1) tarpos = n;

        int cnt = 0;
        int i = tarpos - 1;
        int j = tarpos;
        vector<int> ret;
        ret.reserve(k);

        while(cnt < k){
            double eps1 = pow(2.0,32), eps2 = pow(2.0,32);
            if (i >= 0) eps1 = target - sorted[i];
            if (j < n) eps2 = sorted[j] - target;

            if (eps1 < eps2){
                ret.push_back(sorted[i]);
                i--;
            }
            else{
                ret.push_back(sorted[j]);
                j++;
            }
            cnt++;
        }

        return ret;
    }
};