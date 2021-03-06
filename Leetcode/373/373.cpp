class Solution {
		
		using el = struct {
    		int x, y, i, j;
    	};

    	template <typename T>
    	class comp{
    	public:
    		bool operator()(const T& lhs, const T& rhs){
    			return lhs.x + lhs.y > rhs.x + rhs.y;
    		}
    	};

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        /* on N*M combination tables, next candidate is adjacent cells */

    	int n = nums1.size();
    	int m = nums2.size();
    	vector<vector<int>> ret;

    	if (n==0 || m==0) return ret;

        priority_queue<el, vector<el>, comp<el>> pq;
        vector<vector<int>> visit(n, vector<int>(m, 0));

        pq.push({nums1[0], nums2[0], 0, 0});
        visit[0][0] = 1;
        
        int cnt = 0;
        while(cnt<k && !pq.empty()){
        	el cur = pq.top();
        	initializer_list<int> r = {cur.x, cur.y};
        	ret.emplace_back(r);

        	pq.pop();

        	if (cur.i + 1 < n && visit[cur.i+1][cur.j] == 0){
        		pq.push({nums1[cur.i+1], nums2[cur.j], cur.i + 1, cur.j});
        		visit[cur.i+1][cur.j] = 1;
        	}
        	if (cur.j + 1 < m && visit[cur.i][cur.j+1] == 0){
        		pq.push({nums1[cur.i], nums2[cur.j  +1], cur.i, cur.j + 1});
        		visit[cur.i][cur.j + 1] = 1;
        	}
        	cnt++;
        }

        return ret;

    }
};