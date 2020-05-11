#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> maxpfarr(n, 0);
        
        int maxpf = 0;
        int minval = prices[0];
        //record possible maximum profit from 0th day to ith day
        for (int i = 1; i < n; i++) {
            if (prices[i] <= minval) {
                minval = prices[i];
            }
            else {
                maxpf = max(maxpf, prices[i] - minval);
            }
            maxpfarr[i] = maxpf;
        }

        maxpf = 0;
        int maxval = prices[n - 1];
        int ret_max = 0;
        //iterate reversely to record possible maximum profit from ith day to (n-1)th day;
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] >= maxval) {
                maxval = prices[i];
            }
            else {
                maxpf = max(maxpf, maxval - prices[i]);
            }
            maxpfarr[i] += maxpf;
            ret_max = max(ret_max, maxpfarr[i]);
        }

        return ret_max;
    }
};

int main()
{
    Solution sol;

    vector<int> in;
    int ret;

    in = vector<int>({3,3,5,0,0,3,1,4});
    ret = sol.maxProfit(in);

    in = vector<int>({ 1,2,3,4,5 });
    ret = sol.maxProfit(in);

    in = vector<int>({ 7,6,4,3,1 });
    ret = sol.maxProfit(in);

    return 0;
}