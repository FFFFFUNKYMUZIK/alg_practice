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

/*
     1
  2     3
4   5
 
 output : 11(3,1,2,5)

    -1
  2    3

  output : 4(2,-1,3)
    1
  2    3
-4  -5

output : 6(1, 2, 3)

*/

//Submission detail(runtime) is unreliable.
class Solution {
public:

    int maxval;

    int traverse(TreeNode* root) {
        if (!root) return 0;

        int lpath = traverse(root->left);
        int rpath = traverse(root->right);

        int tmp = root->val + max(lpath, 0) + max(rpath, 0);
        maxval = max(maxval, tmp);

        return root->val + max(max(lpath, rpath), 0);
    }

    int maxPathSum(TreeNode* root) {
        maxval = INT_MIN;
        traverse(root);
        return maxval;
    }
};


int main()
{
    return 0;
}