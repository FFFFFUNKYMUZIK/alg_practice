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

class Solution {
public:

    int sum;

    void traverse(TreeNode* root, int val) {
        if (!root) {
            return;
        }

        int cur = val * 10 + root->val;
        if (!root->left && !root->right) {
            sum += cur;
            return;
        }
        
        traverse(root->left, cur);
        traverse(root->right, cur);
    }

    int sumNumbers(TreeNode* root) {
        sum = 0;
        traverse(root, 0);
        return sum;
    }
};

int main()
{
    return 0;
}
