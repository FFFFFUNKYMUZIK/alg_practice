class Solution {
	/*
	Note:
	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
	Input words contain only lowercase letters.
	
	Follow up:
	Try to solve it in O(n log k) time and O(n) extra space.
	*/
 
        class el {
        public:
        	el(int c, string s) : cnt(c), str(s){};
        	int cnt;
        	string str;
        };

        template <typename T>
        class comp{
        public:
        	bool operator()(const T& lhs, const T& rhs){
        		if (lhs.cnt == rhs.cnt){
        			return lhs.str < rhs.str;
        		}		
        		return lhs.cnt > rhs.cnt;
        	}
        };


public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        int n = words.size();
        unordered_map<string, int> cnt;
        

        for (int i=0;i<n;i++){
        	cnt[words[i]]++;
        }
       
        priority_queue<el, vector<el>, comp<el>> pq;
        for (auto e : cnt){
        	el cur(e.second, e.first);
        	pq.push(cur);
        	if (pq.size() > k) pq.pop();
        }

        vector<string> ret(pq.size(), "");
        int i = pq.size() - 1;

        while(!pq.empty()){
        	ret[i--] = pq.top().str;
        	pq.pop();
        }

        return ret;
    }
};