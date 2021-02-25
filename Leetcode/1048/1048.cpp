class Solution {
public:
    int longestStrChain(vector<string>& words) {

    	sort(words.begin(), words.end(), [](const string& lhs, const string& rhs)
    									{return lhs.length() < rhs.length();});

    	unordered_map<string, int> hash;
    	int maxlen = 1;

    	for (int i=0;i<words.size();i++){
    		string& cur = words[i];
    		string pre;
    		int tmpmax = 0;
    		for (int j=0;j<cur.length();j++){
    			pre = cur.substr(0, j) + cur.substr(j+1, cur.length() - j - 1);
    			if (hash.find(pre) != hash.end()){
    				tmpmax = max(tmpmax, hash[pre] + 1);
    			}
    		}

    		if (tmpmax > 0){
    			hash[cur] = max(tmpmax, hash[cur]);
    			maxlen = max(maxlen, tmpmax);
    		}
    		else{
    			hash[cur] = 1;
    		}

    	}
        
        return maxlen;
    }
};