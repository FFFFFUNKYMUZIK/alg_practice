class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
    	unordered_map<int, int> cnt;

    	for (auto e : arr)
    		cnt[e]++;
    	
    	using el = struct{
    		int val; int cnt;
    	};

    	using compf = struct{
    		bool operator()(const el& lhs, const el& rhs){
    			return lhs.cnt < rhs.cnt;
    		}
    	};

    	vector<el> entry;
    	for (auto e : cnt)
    		entry.push_back({e.first, e.second});

    	sort(entry.begin(), entry.end(), compf());

    	int i = 0;
    	for (auto e : entry){
    		k -= e.cnt;
    		if (k<0) break;
    		i++;
    	}

    	return entry.size() - i;
    }
};