class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;

        int i=1;
        int ppre = 0, pre = 1;
        int cur;

        while(i<n){
        	cur = ppre + pre;
        	ppre = pre;
        	pre = cur;
        	i++;
        }

        return cur;
    }
};