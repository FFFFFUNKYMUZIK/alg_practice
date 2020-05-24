#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 0));

        while (!st.empty()) {
            TreeNode* cur = st.top().first;
            int flag = st.top().second;
            st.pop();

            if (flag == 0) {
                st.push(make_pair(cur, 1));
                if (cur->right) st.push(make_pair(cur->right, 0));
                if (cur->left) st.push(make_pair(cur->left, 0));
                
            }
            else if (flag == 1) {
                ret.push_back(cur->val);
            }

        }
        return ret;
    }
};

int main()
{
    return 0;
}
