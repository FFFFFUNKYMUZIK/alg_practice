class Solution {
public:
    vector<int> partitionLabels(string S) {
        
    	int len = S.length();
    	unordered_map<char, int> max_idx;

    	for (int i=0;i<len;i++){
    		max_idx[S[i]] = i;
    	}

    	int end = -1;
    	int cnt = 0;
    	vector<int> ret;

    	for (int i=0;i<len;i++){
    		cnt++;
    		end = max(end, max_idx[S[i]]);

    		if (end==i){
    			ret.push_back(cnt);
    			cnt = 0;
    		}
    	}

    	return ret;
    }
};