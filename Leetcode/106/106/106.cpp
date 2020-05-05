#include <iostream>
#include <vector>
#include <unordered_map>

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

    // l x r
    TreeNode* buildTree_sub(vector<int>& inorder, int l, int r, unordered_map<int, int>& um, vector<int>& postorder, int x) {
        int n = r - l + 1;
        if (n <= 0) return NULL;

        int cval = postorder[x];
        int idx = um[cval];
        TreeNode* cn = new TreeNode(cval);

        cn->left = buildTree_sub(inorder, l, idx - 1, um, postorder, x - (r - idx) -1);
        cn->right = buildTree_sub(inorder, idx + 1, r, um, postorder, x - 1);

        return cn;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return NULL;

        unordered_map<int, int> um;
        for (int i = 0; i < n; i++) { um[inorder[i]] = i; }
        return buildTree_sub(inorder, 0, n - 1, um, postorder, n-1);
    }
};


int main()
{
    return 0;
}
