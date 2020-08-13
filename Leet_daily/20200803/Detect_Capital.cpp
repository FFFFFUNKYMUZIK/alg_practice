class Solution {
public:
    bool detectCapitalUse(string word) {
        
        char s = word[0];
        bool lowercase = false;
        int start = 1;
        if ('a'<=s && s<='z'){
            lowercase = true;
        }
        else if ('A'<=s && s<='Z'){
            lowercase = false;
        }
        else{
            return false;
        }
        
        if (word.length()>=2 && !lowercase){
            char c = word[1];
            if ('a'<=c && c<='z'){
                lowercase = true;
            }
            else if ('A'<=c && c<='Z'){
                lowercase = false;
            }
            else{
                return false;
            }
            start++;
        }
        
        for (int i=start;i<word.length();i++){
            char c = word[i];
            if ( !((lowercase && ('a'<=c && c<='z')) ||
                 (!lowercase && ('A'<=c && c<='Z'))) )
                return false;
            
        }
        
        return true;
    }
};