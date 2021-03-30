class Solution {

public:
    int deleteAndEarn(vector<int>& nums) {

    	int n = nums.size();
    	sort(nums.begin(), nums.end(), less<int>());

    	vector<int> b, cnt;

    	int i =0;
    	while(i<n){
    		int curcnt = 1;
    		while (i<n-1 && nums[i] == nums[i+1]){
    			curcnt++;
    			i++;
    		}
    		b.push_back(nums[i]);
    		cnt.push_back(curcnt);

    		i++;
    	}

    	int d = b.size();
    	vector<int> p(d, 0), np(d, 0);
    	p[0] = b[0]*cnt[0];

    	int pre = b[0];
    	int premax;
    	for (int i=1;i<d;i++){
    			premax = max(p[i-1], np[i-1]);
    		if (pre != b[i] - 1){
    			p[i] = premax + b[i]*cnt[i];
    			np[i] = premax;
    		}
    		else{
    			p[i] = np[i-1] + b[i]*cnt[i];
    			np[i] = premax;
    		}

    		pre = b[i];
    	}

    	return max(p[d-1], np[d-1]);
    }
};