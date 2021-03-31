class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
                
    	int n = nums.size();
    	vector<double> ret(n - k + 1, 0.0);

    	if (k==1){
    		for (int i=0;i<n;i++) ret[i] = nums[i];
    			return ret;
    	}

    	/* half max heap */
    	priority_queue<int, vector<int>, less<int>> lh;
    	/* half min heap */
    	priority_queue<int, vector<int>, greater<int>> rh;
    	/* count of element that is to be removed */
    	unordered_map<int, int> cnt;

    	for (int i=0;i<k;i++){
    		lh.push(nums[i]);
    	}

    	for (int i=0;i<k/2;i++){
    		rh.push(lh.top());
    		lh.pop();
    	}

    	int lsize = lh.size(), rsize = rh.size();

    	double mid;
    	if (k%2 == 0){
    		mid = lh.top()/2.0 + rh.top()/2.0;
    	}
    	else{
    		mid = lh.top();
    	}

    	ret[0] = mid;
    	int idx = 1;

    	for (int i=k;i<n;i++, idx++){
    		cnt[nums[i-k]]++;

    		if (nums[i] <= lh.top()){
    			lh.push(nums[i]);
    			lsize++;
    		}
    		else{
    			rh.push(nums[i]);
    			rsize++;
    		}

    		if (nums[i-k] <= lh.top()){
    			lsize--;
    		}
    		else{
    			rsize--;
    		}

    		int del = k%2;
    		
    		if (lsize > rsize + del){
    			rh.push(lh.top());
    			lh.pop();
    			lsize--;
    			rsize++;
    		}
    		else if (lsize < rsize + del){
    			lh.push(rh.top());
    			rh.pop();
    			lsize++;
    			rsize--;
    		}

    		while(cnt[lh.top()] > 0){
    			cnt[lh.top()]--;
    			lh.pop();
    		}
    		while(cnt[rh.top()] > 0){
    			cnt[rh.top()]--;
    			rh.pop();
    		}

    		if (k%2){
    			mid = lh.top();
    		}
    		else{
    			mid = lh.top()/2.0 + rh.top()/2.0;
    		}

    		ret[idx] = mid;
    	}

    	return ret;
    }
};