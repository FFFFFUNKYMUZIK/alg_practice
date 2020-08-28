class Solution {
public:
    
    int cnt = 0;
    unordered_map<char,char> um;
    
    bool isRange(string& lower, string& higher, string& tar){
        
        int lowlen = lower.length();
        int highlen = higher.length();
        
        int tarlen = tar.length();
        
        if (tarlen > highlen || tarlen < lowlen) return false;
        
        
        if (tarlen == lowlen){
            for (int c=0;c<tarlen;c++){
                if (lower[c]==tar[c]) continue;
                if (lower[c]<tar[c]) break;
                if (lower[c]>tar[c]) return false;
            }
        }
        
        if (tarlen == highlen){
            for (int c=0;c<tarlen;c++){
                if (higher[c]==tar[c]) continue;
                if (higher[c]>tar[c]) break;
                if (higher[c]<tar[c]) return false;
            }
        }
        
        return true;
    }
    
    
    void backtrack(int i, int& len, string& str, string& lower, string& higher){
         if (i==(len+1)/2){
            if (isRange(lower, higher, str)) cnt++;
            return;
        }
        
        for (auto it = um.begin();it!=um.end();it++){
            if (i==0 && it->first == '0') continue;
            if (i==len/2 && len%2 == 1 && (it->first == '6' || it->first == '9')) continue;
            
            str[i] = it->first;
            str[len-i-1] = it->second;
            backtrack(i+1, len, str, lower, higher);
        }

    }
    
    int strobogrammaticInRange(string low, string high) {

        unordered_map<char, char>().swap(um);
        um['0'] = '0';
        um['1'] = '1';
        um['6'] = '9';
        um['8'] = '8';
        um['9'] = '6';
        
        int lowlen = low.length(), highlen = high.length();
        
        string str;
        for (int c = lowlen;c<=highlen;c++){
            str.resize(c);    
            backtrack(0, c, str, low, high);
        }
        
        if (low==string("0")) cnt++;
        
        return cnt;
    }
};