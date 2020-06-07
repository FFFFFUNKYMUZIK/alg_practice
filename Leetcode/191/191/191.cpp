#include <iostream>

/*
Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above the input represents the signed integer -3.


Follow up:

If this function is called many times, how would you optimize it?
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n -= (n & (-n));
            ret++;
        }
        return ret;
    }
};

int main()
{
    Solution sol;

    int ret;
    uint32_t in;

    in = 0b00000000000000000000000000001011;
    ret = sol.hammingWeight(in);

    in = 0b00000000000000000000000010000000;
    ret = sol.hammingWeight(in);

    in = 0b11111111111111111111111111111101;
    ret = sol.hammingWeight(in);

    return 0;
}
