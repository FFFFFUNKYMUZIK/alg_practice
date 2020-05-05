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

    TreeNode* buildTree_sub(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int>& um) {
        int n = pe - ps + 1;
        if (n <= 0) return NULL;

        int cval = preorder[ps];
        TreeNode* cn = new TreeNode(cval);

        int idx = um[cval];
        int cnt = idx - is;

        cn->left = buildTree_sub(preorder, ps + 1, ps + cnt, inorder, is, is + cnt - 1, um);
        cn->right = buildTree_sub(preorder, ps + cnt + 1, pe, inorder, is + cnt + 1, ie, um);

        return cn;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return NULL;

        unordered_map<int, int> um;
        for (int i = 0; i < n; i++) {
            um[inorder[i]] = i;
        }
        return buildTree_sub(preorder, 0, n - 1, inorder, 0, n-1, um);
    }
};

int main()
{
    return 0;
}
