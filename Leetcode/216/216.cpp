class Solution {
    
    vector<vector<int>> ret;
    int tar;
    int len;
    
    void backtrack(vector<int>& bucket, int s, int sum){

        if (tar == sum){
            if (bucket.size()==len){
                ret.push_back(bucket);
            }
            return;
        }
        
        for (int i=s;i<=tar - sum && i < 10 && bucket.size()<len;i++){
            bucket.push_back(i);
            backtrack(bucket, i+1, sum+i);
            bucket.pop_back();
        }        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>().swap(ret);
        vector<int> bucket;
        tar = n;
        len = k;
        backtrack(bucket, 1, 0);
        
        return ret;
    }
};