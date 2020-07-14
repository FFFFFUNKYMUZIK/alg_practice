class Solution {
public:
    
    typedef pair<int,char> op;
    vector<vector<vector<op>>> dp;   
    
    vector<op> getop(vector<op>& ops, int s, int e){
        if (s==e) return vector<op>({ops[s]});
        
        vector<op> &ret = dp[s][e];
        vector<op> l, r;
        
        if (!ret.empty()) return ret;
        
        for (int i=s;i<e;i++){
            l = getop(ops, s, i);
            r = getop(ops, i+1, e);
            
            for (auto le : l){
                for (auto re : r){
                    op cur;
                   
                    if(le.second == '+'){
                        cur.first = le.first+re.first;
                    }
                    else if(le.second == '-'){
                        cur.first = le.first-re.first;
                    }
                    else{
                        cur.first = le.first*re.first;
                    }
                    cur.second = re.second;
                    ret.push_back(cur);
                }
            }
        }

        return ret;
    }
    
    
    vector<int> diffWaysToCompute(string input) {
        
        int n = input.length();
        
        int digit=0;
        
        vector<op> ops;
        
        for (int i=0;i<n;i++){
            char c = input[i];
                if (c>='0' && c<='9'){
                    digit  = digit*10 + (c-'0');
                }
                else {
                    ops.push_back(make_pair(digit, c));
                    digit=0;
                }
        }
        ops.push_back(make_pair(digit, '.'));
        int opnum = ops.size();
        
        dp = vector<vector<vector<op>>>(opnum, vector<vector<op>> (opnum, vector<op>()));
        
        ops = getop(ops, 0, opnum-1);
        
        vector<int> ret;
        for (int i=0;i<ops.size();i++){
            ret.push_back(ops[i].first);
        }
        return ret;
    }
};