class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ret;

        vector<priority_queue<int, vector<int>, less<int>>> bucket(1001);

        for (auto i : items){
        	bucket[i[0]].push(i[1]);
        }

        for (int i = 0; i<bucket.size(); i++){
        	if (!bucket[i].empty()){
        		int idx = 0;
        		int sum = 0;
        		while(idx<5){
        			sum += bucket[i].top();
        			bucket[i].pop();
        			idx++;
        		}

        		ret.push_back({i, sum/5});
        	}
        }

        return ret;
    }
};