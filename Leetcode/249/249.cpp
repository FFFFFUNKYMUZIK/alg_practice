class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        unordered_map<string, vector<string>> bucket;

        for (int i=0;i<n;i++){
            string& cur = strings[i];
            string key(cur.length(), '0');
            for(int j=0;j<cur.length();j++){
                key[j] = cur[j]- cur[0]+ 'a';
                if (cur[j]-cur[0]< 0) key[j] += 26;
            }
            bucket[key].push_back(cur);
        }    
        
        vector<vector<string>> ret;
        
        for (auto it = bucket.begin();it!=bucket.end();it++){
            ret.push_back(it->second);
        }
        
        return ret;
    }
};