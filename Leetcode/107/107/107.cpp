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


    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<vector<int>> tmp;
        
        queue<TreeNode*> q;
        q.push(root);

        while (1) {
            queue<TreeNode*> nq;
            vector<int> bucket;

            TreeNode* cn;
            while (!q.empty()) {
                cn = q.front();
                q.pop();

                if (!cn) continue;

                bucket.push_back(cn->val);
                nq.push(cn->left);
                nq.push(cn->right);
            }

            if (bucket.empty()) break;
            tmp.push_back(bucket);
            q.swap(nq);
        }

        ret.resize(tmp.size());
        for (int i = 0; i < tmp.size(); i++) {
            ret[i] = tmp[tmp.size()-i-1];
        }

        return ret;

    }
};

int main()
{
    return 0;
}
