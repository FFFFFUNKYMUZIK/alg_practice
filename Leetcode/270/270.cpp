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
    int closestValue(TreeNode* root, double target) {
        
        double eps = pow(2.0,32), cureps = 0.0;

        TreeNode* cur = root;
        TreeNode* susp = root;

        while(1){
            if (target < cur->val){
                cureps = cur->val - target;
                if (cureps < eps){
                    eps = cureps;
                    susp = cur;
                }

                if (cur->left){
                    cur = cur->left;
                }
                else break;
            }
            else{
                cureps = target - cur->val;
                if (cureps < eps){
                    eps = cureps;
                    susp = cur;
                }

                if (cur->right){
                    cur = cur->right;
                }
                else break;
            }
        }
        return susp->val;
    }
};