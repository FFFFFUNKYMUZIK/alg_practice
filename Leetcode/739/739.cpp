class Solution {
	using pii = pair<int,int>;

public:

    vector<int> dailyTemperatures(vector<int>& T) {
    	int n = T.size();
    	if (n==0) return vector<int>();

        vector<int> ret(n, 0);

        struct tcmp{
        	bool operator()(const pii& lhs, const pii& rhs){ return lhs.first > rhs.first;};
        };

        priority_queue<pii, vector<pii>, tcmp> pq;

        for (int i=0;i<n;i++){
        	while(!pq.empty() && pq.top().first < T[i]){
				ret[pq.top().second] = i - pq.top().second;
        		pq.pop();
        	}
        	pq.push({T[i], i});
        }

        return ret;
    }
};