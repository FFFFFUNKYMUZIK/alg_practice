class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        
        sort(A.begin(), A.end());

        int until = -1;
        int cnt = 0;
        for (auto e : A){
        	if (e > until)
        		until = e;
        	else
        		cnt += (++until - e);
        }

        return cnt;
    }
};