#if 0

// L(n) indicates the maximum profit when consider first&last home not to be neighbor.
// L(n) = max(L(n-3), L(n-2)) + a(n) 
// C(n) indicates the maximum profit when consider first&last home to be neighbor. (except for C(0) = 0 so that further recursion is valid)
// C(n) = max(C(n-3), C(n-2)) + a(n) 
// same recursion relation, but different I.C.

class Solution {
public:
    int rob(vector<int>& nums) {
        int ret=0;
        int n = nums.size();
        if (n==0) return ret;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
                
        vector<int> Ln(n, 0), Cn(n, 0);
        Ln[0] = nums[0];        
        Cn[0] = 0;
        Ln[1] = Cn[1] = nums[1];
        Ln[2] = Ln[0] + nums[2];
        Cn[2] = nums[2];
        
        for (int i=3;i<n;i++){
            Ln[i] = max(Ln[i-3],Ln[i-2]) + nums[i];
            Cn[i] = max(Cn[i-3],Cn[i-2]) + nums[i];
        }
        
        return max(max(Ln[n-3], Ln[n-2]), Cn[n-1]);
    }
};

#else

/*
Hint 1
Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.
*/

class Solution {
    
    int robrange(int s, int e, vector<int>& nums){               
        vector<int> dp(e-s+1, 0);
        
        dp[0] = nums[s];
        dp[1] = nums[s+1];
        int cnt = 2;
        if (e-s>=2){
            dp[2] = dp[0]+nums[s+2];
            cnt++;

            for (int i=s+3;i<=e;i++, cnt++){
                dp[cnt] = max(dp[cnt-3],dp[cnt-2]) + nums[i];
            }
        }
        
        return max(dp[cnt-1], dp[cnt-2]);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
        
        return max(robrange(0, n-2, nums), robrange(1, n-1, nums));
    }
};



#endif