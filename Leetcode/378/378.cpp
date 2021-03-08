class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<vector<char>> visit(n, vector<char>(n,0));

        using el = struct {
        	int val;
        	int x, y;
        };

        using comp = struct{
        	bool operator()(const el& lhs, const el& rhs){
        		return lhs.val > rhs.val; 
        	}
        };

        priority_queue<el, vector<el>, comp> pq;

        pq.push({matrix[0][0], 0, 0});
        visit[0][0] = 1;

        el cur = pq.top();
        while(k>0){
        	cur = pq.top();
        	pq.pop();
        	k--;

        	if (cur.x + 1 < n && visit[cur.x + 1][cur.y] == 0){
        		pq.push({matrix[cur.x + 1][cur.y], cur.x+1, cur.y});
        		visit[cur.x + 1][cur.y] = 1;
        	}

        	if (cur.y + 1 < n && visit[cur.x][cur.y + 1] == 0){
        		pq.push({matrix[cur.x][cur.y  + 1], cur.x, cur.y + 1});
        		visit[cur.x][cur.y + 1] = 1;
        	}
        }

        return cur.val;
    }
};