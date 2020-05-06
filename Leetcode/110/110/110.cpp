#include <iostream>
#include <algorithm>

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

    int treedepth(TreeNode* root) {
        if (!root) return 0;

        int ld = treedepth(root->left);
        if (ld == -1) return -1;
        int rd = treedepth(root->right);
        if (rd == -1) return -1;
        int diff = abs(ld - rd);
        if (diff > 1) return -1;
        
        return max(ld, rd) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (treedepth(root) == -1) return false;
        return true;
    }
};


int main()
{
    return 0;
}
