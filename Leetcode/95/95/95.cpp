#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(-1), left(NULL), right(NULL) {}
};

#if 0

//recursion, share same subtree
//hard to release memories because trees shares their subtrees
class Solution {
public:

    vector<TreeNode*> makeTree(int s, int e) {

        vector<TreeNode*> ret;

        if (e < s) {
            ret.push_back(NULL);
            return ret;
        }

        vector<TreeNode*> lsub;
        vector<TreeNode*> rsub;
        TreeNode* cur;

        for (int i = s; i <= e; i++) {
            lsub = makeTree(s, i - 1);
            rsub = makeTree(i + 1, e);

            for (int j = 0; j < lsub.size(); j++) {
                for (int k = 0; k < rsub.size(); k++) {
                    cur = new TreeNode(i);
                    cur->left = lsub[j];
                    cur->right = rsub[k];
                    ret.push_back(cur);
                }
            }
        }

        return ret;
    }

    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return makeTree(1, n);
    }

};

#elif 0

//recursion, do not share same subtree
//can release all nodes
//easy to handle each tree of result vector

class Solution {
public:

    vector<TreeNode*> makeTree(int s, int e) {

        vector<TreeNode*> ret;

        if (e < s) {
            ret.push_back(NULL);
            return ret;
        }
                
        TreeNode* cur;

        for (int i = s; i <= e; i++) {

            vector<vector<TreeNode*>> lsubs;
            vector<vector<TreeNode*>> rsubs;
            
            int lsize, rsize;
            lsubs.push_back(makeTree(s, i - 1));
            rsubs.push_back(makeTree(i + 1, e));

            lsize = lsubs[0].size();
            rsize = rsubs[0].size();

            for (int j = 1; j < lsize; j++) {
                rsubs.push_back(makeTree(i + 1, e));
            }

            for (int j = 1; j < rsize; j++) {
                lsubs.push_back(makeTree(s, i - 1));
            }

            for (int j = 0; j < lsize; j++) {
                for (int k = 0; k < rsize; k++) {
                    cur = new TreeNode(i);
                    cur->left = lsubs[k][j];
                    cur->right = rsubs[j][k];
                    ret.push_back(cur);
                }
            }
        }

        return ret;
    }


    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return makeTree(1, n);
    }

    void release(TreeNode* root) {
        if (!root) return;
        release(root->left);
        release(root->right);
        free(root);
    }

    void releaseAll(vector<TreeNode*> ret) {
        for (auto pn : ret) {
            release(pn);
        }
    }

};


#else


//recursion, share same subtree
//make each subtree which consists of elements from s to e just once

class Solution {
public:

    vector<vector<vector<TreeNode*>>> dp;
    
    vector<TreeNode*> makeTree(int s, int e) {

        if (e < s) {
            return vector<TreeNode*>(1, NULL);
        }
        vector<TreeNode*>& ret = dp[s][e];

        if (ret.size() != 0) return ret;

        vector<TreeNode*> lsub;
        vector<TreeNode*> rsub;
        TreeNode* cur;

        for (int i = s; i <= e; i++) {
            lsub = makeTree(s, i - 1);
            rsub = makeTree(i + 1, e);

            for (int j = 0; j < lsub.size(); j++) {
                for (int k = 0; k < rsub.size(); k++) {
                    cur = new TreeNode(i);
                    cur->left = lsub[j];
                    cur->right = rsub[k];
                    ret.push_back(cur);
                }
            }
        }

        return ret;
    }


    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        dp = vector<vector<vector<TreeNode*>>>( n+1, vector<vector<TreeNode*>>(n+1));

        return makeTree(1, n);
    }

};




#endif

int main()
{
    Solution sol;
    vector<TreeNode*> ret;

    ret = sol.generateTrees(5);

    //sol.releaseAll(ret);

    return 0;
}
