class Solution {
public:
	/* backtrack, TLE */
#if 0
	bool backtrack(unordered_map<char, int>& hash, int remain, char pre, string& ret){
		if (remain == 0) return true;

		string tmp = ret;

		for (auto it = hash.begin(); it!= hash.end();it++){
			if (it->first == pre) continue;
			if (it->second > (remain + 1)/2) return false;
			if (it->second > 0){
				ret += it->first;
				it->second--;
				if (backtrack(hash, remain - 1, it->first, ret))
					return true;
				it->second++;
				ret = tmp;
			}
		}

		return false;
	}

    string reorganizeString(string S) {
    	int len = S.length();
    	string ret;

    	unordered_map<char, int> hash;

    	for (int i=0;i<len;i++){
    		hash[S[i]]++;
    	}

    	backtrack(hash, len, ' ',ret);

        return ret;
    }
    #else

	#define ALP 26
	using e = struct {char c; int freq;};

    string reorganizeString(string S) {
    	int len = S.length();
    	string ret;
    	int cnt = 0;

		vector<e> buc(ALP, {0, 0});

    	for (int i=0;i<len;i++){
    		buc[S[i] - 'a'].c = S[i];
    		buc[S[i] - 'a'].freq++;
    	}

    	using comp = struct {
    		bool operator()(const e& lhs, const e& rhs){return lhs.freq < rhs.freq;};
    	};

		priority_queue<e, vector<e>, comp> pq;

		for (int i=0;i<ALP;i++){
			if (buc[i].freq > 0){
				pq.push(buc[i]);
			}
		}   	

    	int i=0;
    	char pre = ' ';
    	e cur;

    	while(i<len){
    		cur = pq.top();
    		pq.pop();

    		if (cur.c == pre){
    			if (pq.empty()) return string();
    			e nxt = pq.top();
    			pq.pop();
    			ret += nxt.c;
    			pre = nxt.c;
    			nxt.freq--;
    			if (nxt.freq > 0)
    				pq.push(nxt);
    			pq.push(cur);
    		}
    		else{
    			ret += cur.c;
    			pre = cur.c;
    			cur.freq--;
    			if (cur.freq > 0)
    				pq.push(cur);
    		}

    		i++;
    	}

        return ret;
    }
    #endif

};