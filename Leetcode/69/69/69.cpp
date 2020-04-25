#include <iostream>

class Solution {
public:

    typedef long long ll;

    int mySqrt(int x) {
        if (x <= 1) return x;
        ll square;

        ll s = 1;
        ll e = x;

        int ret;

        while (s <= e) {
            ll mid = (s + e) / 2;

            square = mid * mid;

            if (square > x) {
                e = mid - 1;
            }
            else if (square < x){
                ret = mid;
                s = mid + 1;
            }
            else {
                return mid;
            }
        }

        return ret;
    }
};


int main()
{
    Solution sol;

    int ret;

    ret = sol.mySqrt(4);

    ret = sol.mySqrt(8);

    ret = sol.mySqrt(INT_MAX);


    return 0;

}
