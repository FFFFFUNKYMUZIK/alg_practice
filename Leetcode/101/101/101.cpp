#include <iostream>
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


// Follow up : Solve it both recursively and iteratively.
class Solution {
public:

    bool isSymmetric_rec(TreeNode* lhs, TreeNode* rhs) {
        if (!lhs && !rhs) return true;
        else if (!lhs || !rhs) return false;
        return (lhs->val==rhs->val) && isSymmetric_rec(lhs->left, rhs->right) && isSymmetric_rec(lhs->right, rhs->left);
    }

    bool isSymmetric_iter(TreeNode* root) {
        queue<TreeNode*> lnodes, rnodes;

        lnodes.push(root->left);
        rnodes.push(root->right);

        TreeNode* ln,* rn;

        while (!lnodes.empty() && !rnodes.empty()) {
            ln = lnodes.front();
            rn = rnodes.front();
            lnodes.pop();
            rnodes.pop();

            if (!ln && !rn) continue;
            if (!ln || !rn) return false;

            if (ln->val != rn->val) return false;
            lnodes.push(ln->left);
            lnodes.push(rn->left);
            rnodes.push(rn->right);
            rnodes.push(ln->right);
        }
        if (lnodes.size() != rnodes.size()) return false;

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return isSymmetric_rec(root->left, root->right);
        //return isSymmetric_iter(root);
    }
};

int main()
{
    return 0;
}