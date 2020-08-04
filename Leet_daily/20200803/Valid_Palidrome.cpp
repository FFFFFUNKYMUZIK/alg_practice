class Solution {
public:
  
    bool isPalindrome(string s) {
        
        int i=0, j=s.length()-1;
        char gap = 'a'-'A';
        
        while(i<j){
            if(!isalpha(s[i]) && !isdigit(s[i])){
                i++;
                continue;   
            }
            
            if(!isalpha(s[j]) && !isdigit(s[j])){
                j--;
                continue;
            }
                        
            if (s[i]!=s[j]){
                if ((isalpha(s[i]) && isdigit(s[j])) ||
                    (isdigit(s[i]) && isalpha(s[j]))){
                    return false;
                }
                else if (isalpha(s[i])){
                    if (abs(s[i]-s[j]) != gap){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};