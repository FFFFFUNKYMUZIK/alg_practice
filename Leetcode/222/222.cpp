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

#if 0

//recursion, O(N)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left)+countNodes(root->right) + 1;
    }
};

#else

//queue, O(N)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* pcur = q.front();
            q.pop();
            if (!pcur) continue;
            
            cnt++;
            q.push(pcur->left);
            q.push(pcur->right);
        }
               
        return cnt;
    }
};


#endif