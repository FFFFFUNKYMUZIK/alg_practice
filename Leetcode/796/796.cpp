class Solution {
public:
    
    vector<int> getPi(string S){
        int n = S.length();
        if (n==0) return vector<int>();

        vector<int> ret(n, 0);

        int j = 0;
        for(int i=1;i<n;i++){
        	while(j>0 && S[j] != S[i]) j = ret[j - 1];
        	if (S[j] == S[i]) ret[i] = ++j;
        }

    	return ret;
	}
    
    
    bool rotateString(string A, string B) {
        int m = A.length();
        int n = B.length();
        if (m != n) return false;
        
        string Ad = A + A;
        vector<int> Bpi = getPi(B);
        int j = 0;
        
        for (int i=0;i<2*n;i++){
        	while (j>0 && Ad[i] != B[j]) j = Bpi[j-1];
        	if (Ad[i] == B[j]) j++;
        	if (j==n) break;
        }
        
        return j == n;
    }
};