#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#if 0

//too much memory 
class Solution {
public:

    //return last node of flattened tree
    TreeNode* flatten_sub(TreeNode* root) {
        if (!root) return root;
        
        //preorder traversal
        TreeNode *lend = flatten_sub(root->left);
        TreeNode *rend = flatten_sub(root->right);

        if (!lend && !rend) return root;

        if (lend) {
            lend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        if (rend) return rend;

        return lend;
    }

    void flatten(TreeNode* root) {
        flatten_sub(root);
    }
};

#else

//refer to 4ms submission
//memory usage is also too big.
class Solution {
public:

    TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};

#endif

int main()
{
    Solution sol;

    TreeNode arr[7];
    for (int i = 1; i <= 6; i++) {
        arr[i] = TreeNode(i);
    }

    arr[1].left = &arr[2];
    arr[1].right = &arr[5];

    arr[2].left = &arr[3];
    arr[2].right = &arr[4];

    arr[5].right = &arr[6];

    sol.flatten(&arr[1]);

    return 0;
}