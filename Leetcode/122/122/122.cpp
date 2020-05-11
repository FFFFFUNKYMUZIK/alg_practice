#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int maxpf = 0;
        int minval = prices[0];

        for (int i = 1; i < n; i++) {
            if (prices[i] < prices[i - 1]) {
                maxpf += (prices[i - 1] - minval);
                minval = prices[i];
            }
        }
        maxpf += (prices[n - 1] - minval);

        return maxpf;
    }
};


int main()
{
    int ret;
    Solution sol;
    vector<int> in;

    in = vector<int>({ 7,1,5,3,6,4 });
    ret = sol.maxProfit(in);

    in = vector<int>({ 1,2,3,4,5});
    ret = sol.maxProfit(in);

    return 0;
}
