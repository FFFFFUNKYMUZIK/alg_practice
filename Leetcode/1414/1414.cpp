class Solution {
public:
    int findMinFibonacciNumbers(int k) {
    	if (k==1) return 1;
        vector<int> fib(1, 1);

        int pre = 1;
        int cur = 2;
        int tmp;
        while(cur<=k){
        	fib.push_back(cur);
        	tmp = pre;
        	pre = cur;
        	cur += tmp;
        }

        int minnum = 0;
        for (int i=fib.size()-1;i>=0;i--){
        	if (fib[i]<=k){
        		minnum += k/fib[i];
        		k %= fib[i];
        	}

        	if (k==0) break;
        }

        return minnum;
    }
};