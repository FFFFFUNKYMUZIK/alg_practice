#include <iostream>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

        bool sign = true;
        if (dividend > 0) {
            dividend = -dividend;
            sign = !sign;
        }
        if (divisor > 0) {
            divisor = -divisor;
            sign = !sign;
        }

        int quotient = 0;
        int n = 0;

        while ( divisor >= INT_MIN / 2 && divisor > dividend) {
            divisor = ((unsigned int)divisor<<1);
            n++;
        }

        while (n >= 0) {
            if (dividend <= divisor) {
                quotient |= (1 << n);
                dividend -= divisor;
            }
            divisor >>= 1;
            n--;
        }

        if (!sign) quotient = -quotient;

        return quotient;

    }
};

int main()
{
    Solution sol;

    int ret;

    ret = sol.divide(10, 2);

    ret = sol.divide(10, 3);

    ret = sol.divide(7, -3);
    
    ret = sol.divide(10, -20);

    ret = sol.divide(0, -4);

    ret = sol.divide(INT_MIN, 4);

    ret = sol.divide(INT_MAX, -4);

    ret = sol.divide(INT_MIN, 1);

    return 0;
}
