#include <iostream>
#include <vector>
#include <queue>

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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        queue<TreeNode*> q;
        q.push(root);

        while (1) {
            TreeNode* cn;
            queue<TreeNode*> nq;
            vector<int> level;

            while (!q.empty()) {
                cn = q.front();
                q.pop();

                if (!cn) continue;

                nq.push(cn->left);
                nq.push(cn->right);
                level.push_back(cn->val);
            }
            if (!level.empty()) ret.push_back(level);
            if (nq.empty()) break;

            q.swap(nq);
        }

        return ret;
    }
};

int main()
{



    return 0;
}
