#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if (n == 0) return 0;

        int maxpf = 0;
        int minprice = prices[0];

        for (int i = 1; i < n; i++) {
            if (prices[i] <= minprice) {
                minprice = prices[i];
                continue;
            }
            maxpf = max(maxpf, prices[i]-minprice);
        }
        return maxpf;
    }
};

int main()
{
    Solution sol;
    int ret;

    vector<int> in({7,1,5,3,6,4});

    ret = sol.maxProfit(in);

    in = vector<int>({7,6,4,3,1});

    ret = sol.maxProfit(in);

    return 0;
}
