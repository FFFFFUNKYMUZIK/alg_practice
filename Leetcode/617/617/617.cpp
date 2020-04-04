#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
#if 0
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;

        int sum = 0;

        if (t1 != nullptr) sum += t1->val;
        if (t2 != nullptr) sum += t2->val;
        
        TreeNode* newnode = new TreeNode(sum);
        
        if (t1 != nullptr) {
            newnode->left = mergeTrees(t1->left, newnode->left);
            newnode->right = mergeTrees(t1->right, newnode->right);
            delete t1;
        }
        if (t2 != nullptr) {
            newnode->left = mergeTrees(t2->left, newnode->left);
            newnode->right = mergeTrees(t2->right, newnode->right);
            delete t2;
        }

        return newnode;
    }

};

#elif 0

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;

        int sum = 0;
      
        TreeNode* l1 = nullptr, * r1 = nullptr, * l2 = nullptr, * r2 = nullptr;
        TreeNode* newnode;

        if (t1 != nullptr) {
            l1 = t1->left;
            r1 = t1->right;
            if (t2 != nullptr) {
                t1->val += t2->val;
                l2 = t2->left;
                r2 = t2->right;
                delete t2;
            }
            newnode = t1;
        }
        else {
            l2 = t2->left;
            r2 = t2->right;
            newnode = t2;
        }

        newnode->left = mergeTrees(l1, l2);
        newnode->right = mergeTrees(r1, r2);

        return newnode;
    }

};

#else

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;

        t1->val += t2->val;

        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        //delete t2;

        return t1;
    }

};




#endif


int main()
{
    Solution sol;
    
    return 0;
}