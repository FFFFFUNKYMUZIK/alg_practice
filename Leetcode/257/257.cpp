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
    
    vector<string> ret;
    
    void backtrack(string& st, TreeNode* cur){
        string original = st;
        st+=to_string(cur->val);
        
        if (!cur->left && !cur->right){
            ret.push_back(st);
        }        
        else{
            st+="->";
            if (cur->left){
                backtrack(st, cur->left);
            }
            if (cur->right){
                backtrack(st, cur->right);
            }
        }
        st = original;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>().swap(ret);
        
        if (!root) return ret;
        
        string empty;
        backtrack(empty, root);
        
        return ret;
    }
};