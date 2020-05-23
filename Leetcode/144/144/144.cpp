#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;

        stack<TreeNode*> st;
        st.push(root);

        TreeNode* cur;
        while (!st.empty()) {
            cur = st.top();
            st.pop();

            ret.push_back(cur->val);

            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }

        return ret;
    }
};

int main()
{
    return 0;
}
