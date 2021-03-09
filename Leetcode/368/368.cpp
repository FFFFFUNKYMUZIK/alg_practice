class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

       int n = nums.size();

       vector<vector<int>> b(n, vector<int>());

       sort(nums.begin(), nums.end());

       int maxkey = -1;
       int maxlen = 0;

       for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (nums[i] % nums[j] == 0){
                    if (b[i].size() < b[j].size() + 1){
                        vector<int> nv = b[j];
                        nv.push_back(nums[i]);
                        b[i] = nv;
                    }
                }                

            }
        
            if (b[i].size() == 0){
                b[i] = vector<int>(1, nums[i]);
            }

            if (b[i].size() > maxlen){
                maxlen = b[i].size();
                maxkey = i;
            }
       }
       return b[maxkey];
    }
};