class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

    	int n = rooms.size();

    	stack<int> keys;
    	vector<int> visit(n, 0);
    	int vcnt = 0;

    	keys.push(0);
    	visit[0] = 1;
    	vcnt++;

    	while(!keys.empty()){
    		int cur = keys.top();
    		keys.pop();

    		for (int i=0;i<rooms[cur].size();i++){
    			if (visit[rooms[cur][i]] == 0){
					keys.push(rooms[cur][i]);
					visit[rooms[cur][i]] = 1;
					vcnt++;    				
    			}
    		}
    	}

    	return vcnt==n;
    }
};