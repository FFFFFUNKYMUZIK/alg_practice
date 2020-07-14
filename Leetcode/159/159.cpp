class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
       
        int n = s.length();
        if (n<3) return n;
        
        int distinct = 1;
        int ppre = 0;
        int pre = s[0];
        int maxlen = 2;
        int cont = 1;
        vector<int> dp (n,0);
        dp[0] = 1;
        
        for (int i=1;i<n;i++){
            if (distinct==2){
                if (pre==s[i]){
                    cont++;
                    dp[i]=dp[i-1]+1;
                }
                else if (ppre==s[i]){
                    cont = 1 ;
                    int tmp = ppre;
                    ppre = pre;
                    pre = tmp;                    
                    dp[i]=dp[i-1]+1;
                }
                else{
                    ppre = pre;
                    pre = s[i];
                    dp[i]=cont+1;
                    cont=1;
                }
                
            }
            else{
                if (pre==s[i]) cont++;
                else{
                    distinct++;
                    ppre = pre;
                    pre = s[i];
                    cont=1;
                }
                dp[i] = dp[i-1]+1;    
            }
            
            if (dp[i]>maxlen) maxlen = dp[i];
        }
        
        return maxlen;
    }
};