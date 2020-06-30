//find the longest palindrome which starts from leftmost element using KMP (O(n))
//It's same with finding pattern s[0]s[1]s[2]... from reverse string(s[n-1]s[n-2]s[n-3]...)

class Solution {
    
    vector<int> getpi(string& s){
        int len = s.length();
        vector<int> pi(len, 0);
        
        int j=0;
        for (int i=1;i<len;i++){
            while(j>0 && s[i]!=s[j]) j=pi[j-1];
            if (s[i]==s[j]) pi[i]=++j;    
        }
        
        return pi;
    }
    
public:
    string shortestPalindrome(string s) {
        string ret;
        int len = s.length();
        if (len<=1) return s;
        
        vector<int> pi = getpi(s);
        
        int i=0, j=len-1;
        
        while(i<j){
            while(i>0 && s[i]!=s[j]) i=pi[i-1];
            if (s[i]==s[j]){
                i++;
            }
            j--;
        }
    
        int maxpal;
        //result i is half length of pattern
        if (i==j) maxpal = 2*i + 1;
        else maxpal = 2*i;
    
        for (int k = len-1;k>=maxpal;k--){
            ret+=s[k];
        }
        ret+=s;
    
        return ret;
    }
};