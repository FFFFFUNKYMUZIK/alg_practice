class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
    	unordered_map<int, int> hash;

    	int n = A.size();
    	hash[0] = 1;

    	int psum = 0;
    	for (int i=0;i<n;i++){
    		psum += A[i];
    		psum = (psum % K);
    		if (psum < 0) psum += K;
    		
    		hash[psum]++;
    	}

    	int pair = 0;
    	for (auto it = hash.begin();it!=hash.end();it++){
    		pair += (it->second)*(it->second - 1)/2;
    	}

    	return pair;
    }
};