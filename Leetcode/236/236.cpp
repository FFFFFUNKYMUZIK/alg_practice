/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.


*/

#if 0 
//using sparse table, O(NlogN)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root) return NULL;
        
        int cnt=0;
        
        queue<pair<TreeNode*, int>> qT;
        qT.push(make_pair(root, 0));
        
        unordered_map<TreeNode*, vector<TreeNode*>> umt;
        umt[root] = vector<TreeNode*>({root});
        
        int pd = -1, qd = -1;
        
        //bfs
        while(!qT.empty()){
            TreeNode* cur = qT.front().first;
            int dist = qT.front().second;
            qT.pop();
            
            if (cur==p) {pd=dist;}
            if (cur==q) {qd=dist;}
            
            if (cur->left){qT.push(make_pair(cur->left, dist+1)); umt[cur->left].push_back(cur);}
            if (cur->right){qT.push(make_pair(cur->right, dist+1)); umt[cur->right].push_back(cur);}
            cnt++;
        }
        
        int h = log2(cnt) + 1;
        
        for (int j=1;j<h;j++){
            for (auto it=umt.begin();it!=umt.end();it++){
                vector<TreeNode*> & vt = it->second;
                vt.push_back(umt[vt[j-1]][j-1]);
            }
        }
        
        while (pd>qd){
            int diff=log2(pd-qd);
            p=umt[p][diff];
            pd-=(1<<diff);
        }
        
        while (pd<qd){
            int diff=log2(qd-pd);
            q=umt[q][diff];
            qd-=(1<<diff);
        }
        
        if (p==q) return p;
        
        for (int i=h-1;i>=0;i--){
            if (umt[p][i] != umt[q][i]){
                p=umt[p][i];
                q=umt[q][i];
            }
        }
        
        return umt[p][0];
    }
};

#else

//recursive, O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        
        if (root==p || root==q) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if (l&&r) return root;
        return l? l : r;
    }
};

#endif

