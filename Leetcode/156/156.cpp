/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        
        TreeNode* pre, *leaf, *npre, *nleaf, *nxt, *cur;
        
        pre = leaf = nullptr;
        cur = root;
        
        while(cur){
            nxt = cur->left;
            npre = cur;
            nleaf = cur->right;
            
            cur->left = leaf;
            cur->right = pre;
            
            pre = npre;
            leaf = nleaf;
            cur = nxt;
        }
            
        return pre;
    }
};