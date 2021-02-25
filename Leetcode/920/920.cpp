class Solution {

	using ull = unsigned long long;
#define MODULO (1000000000ULL + 7)

	ull fact(int n){
		if (n<=1) return 1;
		return n*(fact(n-1)%MODULO);
	}
	
public:
    int numMusicPlaylists(int N, int L, int K) {

    	vector<vector<ull>> dp(L + 1, vector<ull>(N + 1, 0));
    	
    	/* dp(K, K) = K! */
    	/* dp(i, j) = j * dp(i - 1, j - 1) + (j - K) * dp(i - 1, j) */

    	dp[K][K] = fact(K);

    	for (ull i=K + 1;i<=L;i++){
    		for (ull j=K+1;j<=i && j<= N;j++){
    			dp[i][j] = (j * dp[i-1][j-1] % MODULO + ((j - K) * dp[i-1][j] % MODULO)) %MODULO;
    		}
    	}

    	return dp[L][N];
    }
};
