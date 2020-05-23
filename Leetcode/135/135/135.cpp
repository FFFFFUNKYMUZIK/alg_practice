#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        if (n <= 1) return n;
        vector<int> candy(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candy[i] = candy[i - 1]+1;
            }
        }

        int sum = candy[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i + 1] + 1, candy[i]);
            }
            sum += candy[i];
        }
        return sum;
    }

};


int main()
{

    Solution sol;
    int ret;
    vector<int> in({ 1,3,3,6,3 });

    ret = sol.candy(in);


    return 0;
}