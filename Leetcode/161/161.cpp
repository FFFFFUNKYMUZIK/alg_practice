class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int slen = s.length();
        int tlen = t.length();
        
        if (abs(slen-tlen) > 1 ) return false;
        if (s==t) return false;
        if (slen==0 || tlen==0) return true;
        
        if (s[0]==t[0]){
            return isOneEditDistance(s.substr(1), t.substr(1));
        }
        else{
            if (slen>tlen){
                return s.substr(1) == t;
            }
            else if (tlen>slen){
                return s == t.substr(1);
            }
            else{
                return s.substr(1) == t.substr(1);
            }
        }
        
        return false;
    }
};