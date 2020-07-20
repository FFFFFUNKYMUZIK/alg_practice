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
    
    pair<int,bool> countUnivalSubtrees_helper(TreeNode* root) {
        if (!root) return make_pair(0,true);        
        
        pair<int,bool> l,r;
        l = countUnivalSubtrees_helper(root->left);
        r = countUnivalSubtrees_helper(root->right);
        
        bool self;
        self = l.second && r.second && ((!root->left) || (root->left->val==root->val)) && ((!root->right) || (root->right->val==root->val));
        int cnt = l.first+r.first;
        if (self) cnt++;
        
        return make_pair(cnt, self);            
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        pair<int,bool> ret = countUnivalSubtrees_helper(root);
        return ret.first;
    }
};