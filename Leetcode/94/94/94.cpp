#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Follow up: Recursive solution is trivial, could you do it iteratively?
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();

        vector<int> ret;
        
        stack<pair<TreeNode*, bool>> st;
        st.push(make_pair( root, 0 ));

        pair<TreeNode*, bool> cur;
        TreeNode* cnode;

        while (!st.empty()) {
            cur = st.top();
            st.pop();

            cnode = cur.first;
            if (!cur.second) {
                if (cnode->right) st.push(make_pair( cnode->right, false ));
                st.push(make_pair( cnode, true ));
                if (cnode->left) st.push(make_pair(cnode->left, false ));
            }
            else {
                ret.push_back(cnode->val);
            }
        }

        return ret;
    }
};


int main()
{
    return 0;
}