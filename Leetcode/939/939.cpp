class Solution {

		struct pair_hash {
		    template <class T1, class T2>
		    std::size_t operator () (const std::pair<T1,T2> &p) const {
		        auto h1 = std::hash<T1>{}(p.first);
		        auto h2 = std::hash<T2>{}(p.second);

		        // Mainly for demonstration purposes, i.e. works but is overly simple
		        // In the real world, use sth. like boost.hash_combine
		        return h1 ^ h2;  
		    }
		};

public:
    int minAreaRect(vector<vector<int>>& points) {
    	int n = points.size();

    	using p = vector<int>;
    	auto comp = [](const p& lhs, const p& rhs){
    		if (lhs[0]==rhs[0]) return lhs[1] < rhs[1];
    		return lhs[0] < rhs[0];
    	};

    	sort(points.begin(), points.end(), comp);


    	int i = 0;
    	using pi = pair<int, int>;
    	unordered_map<pi, int, pair_hash> line;


    	int from = 0;
		int now = 0;

		int minarea = 0x3FFFFFFF;

    	while(i<n){
    		from = i;
    		now = points[i][0];
    		while(i<n && points[i][0] == now) i++;

    		for (int s = from ; s < i; s++){
    			for (int t = s+1; t < i; t++){
    				if (line.find(make_pair(points[s][1], points[t][1]))!= line.end()){
    					minarea = min(minarea, (now - line[make_pair(points[s][1], points[t][1])]) * (points[t][1] - points[s][1]));
    				}
    				line[make_pair(points[s][1], points[t][1])] = now;
    			}
    		}

    	}
    	if (minarea == 0x3FFFFFFF) minarea = 0;

    	return minarea;
    }
};