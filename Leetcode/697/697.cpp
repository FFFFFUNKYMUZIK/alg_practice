class Solution {

	using occur = struct {int idx; int ridx; int cnt;};


public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, occur> hash;
        int n = nums.size();

        for (int i=0;i<n;i++){
        	if (hash.find(nums[i]) != hash.end()){
        		hash[nums[i]].ridx = i;
        		hash[nums[i]].cnt++;
        	}
        	else{
        		hash[nums[i]] = {i, i, 1};
        	}
        }

        int maxcnt = 0;
        int mindist = n;
        for (auto it = hash.begin();it!=hash.end();it++){
        	if (it->second.cnt > maxcnt){
        		maxcnt = it->second.cnt;
        		mindist = it->second.ridx - it->second.idx + 1;
        	}
        	else if (it->second.cnt == maxcnt){
        		if (it->second.ridx - it->second.idx + 1 < mindist){
        			mindist = it->second.ridx - it->second.idx + 1;
        		}
        	}
        }

        return mindist;
    }
};