class Solution {
public:

	/* beautiful arrangement {a}*/
	/* if (i | a[i]) or (a[i] | i) */
	/* num of b.a. = cnt_N */
	/* cnt_N = cnt_(N-1) ( when N does not move ) + alpha( when N moves ) */
	/* 1 2 3 8 ... */

	int count(int N, int cur, vector<int>& visit){
		if (cur > N) return 1;

		int cnt = 0;
		for (int i=1;i<=N;i++){
			if (visit[i]) continue;
			if (i%cur == 0 || cur%i == 0){
				visit[i] = 1;
				cnt += count(N, cur+1, visit);
				visit[i] = 0;
			}
		}
		return cnt;
	}

    int countArrangement(int N) {
    	vector<int> visit(N+1, 0);
    	return count(N, 1, visit);
    }
};