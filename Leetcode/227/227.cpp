class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        
        if (len==0) return 0;
        
        stack<long long> opd;
        stack<char> op;
        
        long long ret = 0;
        long long sign = 1;
        long long val = 0;
        
        s+="+";
        len++;
        
        for (int i=0;i<len;i++){
            if (s[i]>='0' && s[i]<='9'){
                val = val*10 + s[i]-'0';
            }   
            else{
                if (s[i]==' ') continue;
                
                 while(!op.empty()){
                     long long preval = opd.top();
                     opd.pop();
                     char cop = op.top();
                     op.pop();
                     if (cop=='*'){
                         val = preval*val;
                     }
                     else if (cop=='/'){
                         val = preval/val;
                     }
                 }
                
                if (s[i]=='+' || s[i]=='-'){
                    ret+=sign*val;
                    val=0;
                    sign=s[i]=='+'? 1 : -1;
                }
                else if (s[i]=='*' || s[i]=='/'){
                    op.push(s[i]);
                    opd.push(val);   
                    val = 0;
                }
            }
        }
        
        return ret;
    }
};