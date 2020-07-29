/*
Follow up:
Could you do it using only constant space complexity?
*/

//O(NlogN)    
#if 0
class Solution {
public:
    bool verifyPreorder_helper(vector<int>& preorder, int s, int e, int minv, int maxv){

        if (s>e) return true;
        int root = preorder[s];
        if (root<minv || root>maxv) return false;
        if (s==e) return true;
        
        int i;
        for (i=s+1;i<=e;i++){
            if (preorder[i]>root){
                break;
            }
        }
                
        return verifyPreorder_helper(preorder, s+1, i-1, minv, min(maxv, root)) && verifyPreorder_helper(preorder, i, e, max(minv, root), maxv);
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size()==0) return true;
        return verifyPreorder_helper(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }
};

#elif 0

//O(N)
class Solution {
public:
    void verifyPreorder_helper(vector<int>& preorder, int& s, int minv, int maxv){
        if (s == preorder.size()) return;
        int cur = preorder[s];
        if ( cur > maxv || cur < minv) return;
        s++;
                
        verifyPreorder_helper(preorder, s, minv, cur);
        verifyPreorder_helper(preorder, s, cur, maxv);
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size()==0) return true;
        int s = 0;
        verifyPreorder_helper(preorder, s, INT_MIN, INT_MAX);
        return s==preorder.size();
    }
};

#else


//O(N), Space Complexity O(N)
class Solution {
public:
    
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size()==0) return true;
        int s = 0;
        int n = preorder.size();
        
        stack<int> st;
        int minv = INT_MIN;
        
        for (int i=0;i<n;i++){
            int cur = preorder[i];
            
            while(!st.empty() && (st.top()<cur)){
                minv = st.top();
                st.pop();
            }
            if (minv > cur){
                return false;
            }
            
            st.push(cur);
        }
        return true;
    }
};



#endif