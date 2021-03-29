class Solution {
public:
    int connectSticks(vector<int>& sticks) {
    	int n = sticks.size();

    	priority_queue<int, vector<int>, greater<int>> pq;

    	for (auto e : sticks){
    		pq.push(e);
    	}

    	int sum = 0;
    	int cur;
    	while(pq.size() > 1){
    		cur = pq.top();
    		pq.pop();
    		cur += pq.top();
    		pq.pop();

    		sum += cur;
    		pq.push(cur);
    	}

    	return sum;
    }
};