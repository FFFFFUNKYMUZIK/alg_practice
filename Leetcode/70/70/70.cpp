#include <iostream>
#include <vector>

using namespace std;

//Fibonacci
class Solution {
public:

    vector<int> dp;

    int fib(int n) {
        int& ret = dp[n];
        if (ret != -1) return ret;

        return ret = fib(n - 1) + fib(n - 2);
    }


    int climbStairs(int n) {
        dp = vector<int>(n+1, -1);
        if (n>=1) dp[1] = 1;
        if (n>=2) dp[2] = 2;
        return fib(n);
    }
};

int main()
{
    Solution sol;
    int ret;

    ret = sol.climbStairs(2);
    
    ret = sol.climbStairs(3);

    
    return 0;
}