#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        int digit;
        int ret = 0;

        while (x!=0) {
            if (ret > INT_MAX / 10 || ret < (-INT_MAX - 1) / 10) return 0;
            ret *= 10;
            digit = x % 10;
            x = x / 10;
            ret += digit;
        }

        return ret;
    }

    
};

int main()
{
    Solution sol;

    int test = INT_MAX;
    int test2 = -INT_MAX - 1;
    int a = -123;
    int b = a / (-10);

    int ret;
    ret = sol.reverse(INT_MAX);
    ret = sol.reverse(123);
    ret = sol.reverse(-123);



    return 0;
}
