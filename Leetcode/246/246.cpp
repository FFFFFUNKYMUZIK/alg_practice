class Solution {
public:
    //consider '0', 1', '69', '8'
    bool isStrobogrammatic(string num) {
        int n = num.length();
        
        unordered_map<char,char> stro;
        
        stro['0'] ='0';
        stro['1'] ='1';
        stro['6'] ='9';
        stro['9'] ='6';
        stro['8'] ='8';
        
        int i=0, j=n-1;
        
        while(i<=j){
            if (stro.find(num[i]) == stro.end() || stro[num[i]] != num[j]) return false;
            i++;j--;
        }
        
        return true;
    }
};