class Solution {

	#define BUCKET 10000

	template <typename C>
	struct container {
		size_t operator()(const C& c) const{
			int sum = 0;
			for (int i = 0;i<c.size();i++) sum=(sum+c[i])%BUCKET;
			return sum;
		}
	};


public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> ret;

       int slen = s.length();
       int plen = p.length();
       if (plen>slen) return ret;

       unordered_map<vector<int>, int, container<vector<int>>> hash;
       vector<int> refkey(26, 0);
       for (int i=0;i<plen;i++){
       		refkey[p[i]-'a']++;
       }

       hash[refkey] = 1;

       vector<int> key(26, 0);

       for (int i=0;i<plen;i++){
       		key[s[i]-'a']++;
       }

       if (hash.find(key) != hash.end()){
       	ret.push_back(0);
       }

       for (int i=1, j = plen;j<slen;i++,j++){
       		key[s[i-1]-'a']--;
       		key[s[j]-'a']++;
       		if (hash.find(key) != hash.end()){
       			ret.push_back(i);
       		}
       }

       return ret;
    }
};