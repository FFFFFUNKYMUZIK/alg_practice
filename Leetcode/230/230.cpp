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

    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;

        stack<pair<bool, TreeNode*>> st;

        st.push(make_pair(false, root));

        int cnt = 0;


        while (!st.empty()) {
            bool visit = st.top().first;
            TreeNode* cur = st.top().second;
            st.pop();

            if (!visit) {
                if (cur->right) st.push(make_pair(false, cur->right));
                st.push(make_pair(true, cur));
                if (cur->left) st.push(make_pair(false, cur->left));
            }
            else if (++cnt == k) return cur->val;
        }

        return -1;
    }
};
