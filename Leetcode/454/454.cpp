class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
    	int n = A.size();
    	unordered_map<int, int> cnt;
    	int sumcnt = 0;

    	for (int i=0;i<n;i++){
    		for (int j=0;j<n;j++){
    			cnt[A[i]+B[j]]++;
    		}
    	}

    	for (int i=0;i<n;i++){
    		for (int j=0;j<n;j++){
    			if (cnt.find(-C[i]-D[j]) != cnt.end()){
    				sumcnt += cnt[-C[i]-D[j]];
    			}
    		}
    	}

    	return sumcnt;
    }
};