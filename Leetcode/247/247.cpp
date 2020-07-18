class Solution {
public:
    
    unordered_map<char,char> strobo;
    vector<string> ret;
    
    void backtrack(string & str, int c, int len){
        if (c==len/2){
            if (len%2 == 1){
                str[c] = '0';
                ret.push_back(str);    
                str[c] = '1';
                ret.push_back(str);
                str[c] = '8';
                ret.push_back(str);
            }
            else{
                ret.push_back(str);
            }
            return;
        }
         
        
        
        for (auto it = strobo.begin();it!=strobo.end();it++){
            if (c==0 && it->first=='0') continue;    
            str[c] = it->first;
            str[len-1-c] = it->second;
            backtrack(str, c+1, len);
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        strobo['0']='0';
        strobo['1']='1';
        strobo['6']='9';
        strobo['8']='8';
        strobo['9']='6';
        
        vector<string>().swap(ret);
        string bucket(n, '0');
        
        backtrack(bucket, 0, n);
        
        return ret;
    }
};