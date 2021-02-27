class SparseVector {

	int n;
	unordered_map<int, int> val;

public:
    
    SparseVector(vector<int> &nums) {
    	n = nums.size();
    	val = unordered_map<int, int>();
    	for (int i=0;i<n;i++){
    		if (nums[i] != 0){
    			val[i] = nums[i];
    		}
    	}
    }

    int operator[](int idx){
    	if (val.find(idx) != val.end()) return val[idx];
    	else return 0;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if (n != vec.size()) return -1;

        int dotp = 0;
        for (auto x : val){
        	dotp += vec[x.first] * x.second;
        }
        return dotp;
    }

    int size(){
    	return n;
    }
};
/* Follow up: What if only one of the vectors is sparse? */

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);