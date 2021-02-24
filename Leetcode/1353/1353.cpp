class Solution {

	template <typename T>
	class comp{
		public:
		bool operator()(const T& left, const T& right){
			if (left[0] == right[0]){
				return left[1] < right[1];
			}
			return left[0] < right[0];
		}
	};

public:
    int maxEvents(vector<vector<int>>& events) {
        
    	sort(events.begin(), events.end(), comp<vector<int>>());
    	int cnt = 0;
    	int d;

    	priority_queue<int, vector<int>, greater<int>> pq; 
    	int i = 0;

    	while(i<events.size() || !pq.empty()){
    		if (pq.empty()){
    			d = events[i][0];
    		}

    		while(!pq.empty() && pq.top() < d) pq.pop();

    		while(i<events.size() && events[i][0] == d){
    			pq.push(events[i][1]);
    			i++;
    		}

    		if (!pq.empty()){
    			pq.pop();
    			d++;
    			cnt++;
    		}
    	}

    	return cnt;
    }
};