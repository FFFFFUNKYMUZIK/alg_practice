class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        typedef struct sort_idx_t{
        	int Ts;
        	int Te;
        	int i;
        }sort_idx;

        vector<sort_idx> idx(n, {0,0});

        for (int i=0;i<n;i++){
        	idx[i] = {startTime[i], endTime[i], i};
        }

        sort(idx.begin(), idx.end(), [](const auto& lhs, const auto& rhs){ return lhs.Ts == rhs.Ts ? lhs.Te < rhs.Te : lhs.Ts < rhs.Ts;});

        int taridx;
        typedef struct sort_prof_t{
        	int pr;
        	int i;
        }sort_prof;
        vector<sort_prof> bucket(n, {0,0});
        vector<sort_prof>::iterator ita, itb, it;


        int start, end;
        int pr;
        for (int i=n-1;i>=0;i--){
        	taridx = idx[i].i;
        	start = startTime[taridx];
        	end = endTime[taridx];
        	pr = profit[taridx];

        	it = bucket.begin();
        	advance(it, i + 1);

        	if (it != bucket.end()){
                
        	    sort_prof spe = {0, end};
        	    sort_prof sps = {0, start};
                
        		ita = lower_bound(it , bucket.end(), spe, [](const auto & lhs, const auto & rhs){return lhs.i < rhs.i;});
        		itb = lower_bound(it , bucket.end(), sps, [](const auto & lhs, const auto & rhs){return lhs.i < rhs.i;});
                if (ita != bucket.end()){
        		    pr += (*ita).pr;
                }
                if (itb != bucket.end()){
                    pr = max(pr, (*itb).pr);
                }
        	}

        	bucket[i] = {pr, start};
        }

        return bucket[0].pr;
    }
};