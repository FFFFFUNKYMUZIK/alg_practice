#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Follow up :

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution ?
*/

class Solution {
public:

    typedef long long ll;

    ll pre;
    TreeNode* pprenode;
    vector<TreeNode*> suspect;

    void traverse(TreeNode* pn) {
        if (!pn) return;
        traverse(pn->left);
        if (pn->val <= pre) {
            suspect.push_back(pprenode);
            suspect.push_back(pn);
        }
        pre = pn->val;
        pprenode = pn;
        traverse(pn->right);
    }

    void swap(TreeNode* lhs, TreeNode* rhs) {
        int tmp = lhs->val;
        lhs->val = rhs->val;
        rhs->val = tmp;
    }

    void recoverTree(TreeNode* root) {
        if (!root) return;

        pre = LLONG_MIN;
        vector<TreeNode*>().swap(suspect);
        traverse(root);
        if (suspect.size() == 2) swap(suspect[0], suspect[1]);
        if (suspect.size() == 4) swap(suspect[0], suspect[3]);
    }
};

int main()
{

    return 0;
}
