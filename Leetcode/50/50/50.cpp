#include <iostream>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        double mul = x;
        double ret = 1;

        int i = n;
        if (i < 0) ret /= x;

        while(i>0){
            if (i & 1) ret *= mul;
            mul = mul * mul;
            i >>= 1;
            if (ret == INFINITY || ret == 0.0) break;
        }
        while(i<-1){
            if ((i & 1) == 0) ret /= mul;
            mul = mul * mul;
            i >>= 1;
            if (ret == INFINITY || ret == 0.0) break;
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    double ret;

    ret = sol.myPow(2.00000, 10);

    ret = sol.myPow(2.10000, 3);

    ret = sol.myPow(2.00000, -2);

    return 0;
}
