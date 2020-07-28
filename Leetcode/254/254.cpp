class Solution {
public:
    
    vector<vector<int>> ret;
    
    void backtrack(int s, int val, vector<int>& buc){
        if (val==1){
            return;
        }
        
        for (int i=s;i*i<=val;i++){
            if (val%i==0){
                buc.push_back(i);
                buc.push_back(val/i);
                ret.push_back(buc);
                buc.pop_back();
                backtrack(i, val/i, buc);
                buc.pop_back();
            }            
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>>().swap(ret);
        vector<int> buc;
        if (n==1) return ret;
        
        backtrack(2, n, buc);
            
        return ret;
    }
};