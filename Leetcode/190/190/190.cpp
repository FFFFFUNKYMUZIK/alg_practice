#include <iostream>

/*
Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.

Follow up:

If this function is called many times, how would you optimize it?
*/

#if 0

//O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t h = (1 << 31), ret = 0;
        while (n) {
            if (n & 1) ret += h;
            n >>= 1;
            h >>= 1;
        }
        return ret;
    }
};

#else


//optimize using bit operation
//O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t h = (1 << 31), ret = 0;
        uint32_t tmp;
        while (n) {
            tmp = n & (-n);
            n -= tmp;
            ret += h / tmp;
        }
        return ret;
    }
};

#endif

int main()
{
    Solution sol;

    uint32_t in, ret;

    in = 0b00000010100101000001111010011100;
    ret = sol.reverseBits(in);

    in = 0b11111111111111111111111111111101;
    ret = sol.reverseBits(in);


    return 0;
}
