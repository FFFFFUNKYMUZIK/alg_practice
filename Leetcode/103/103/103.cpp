#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ret;
        stack<TreeNode*> st;
        bool ltor = true;
        st.push(root);

        while (1) {
            stack<TreeNode*> nst;
            vector<int> level;
            TreeNode* cn;

            while (!st.empty()) {
                cn = st.top();
                st.pop();

                if (!cn) continue;

                if (ltor) {
                    nst.push(cn->left);
                    nst.push(cn->right);
                }
                else {
                    nst.push(cn->right);
                    nst.push(cn->left);
                }
                level.push_back(cn->val);
            }
            if (!level.empty()) ret.push_back(level);
            if (nst.empty()) break;

            st.swap(nst);
            ltor = !ltor;
        }
        
        return ret;
    }
};

int main()
{



    return 0;
}

