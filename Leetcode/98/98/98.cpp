#include <iostream>
#include <vector>

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

    typedef long long ll;

    ll pre;

    bool traverse(TreeNode* pn) {
        if (!pn) return true;

        if (!traverse(pn->left)) return false;
        if (pn->val <= pre) return false;
        pre = pn->val;
        if (!traverse(pn->right)) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        pre = LLONG_MIN;
        return traverse(root);
    }
};


using namespace std;

int main()
{
    return 0;
}
