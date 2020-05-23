#include <iostream>
#include <vector>

using namespace std;

/*
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#if 0

class Solution {
public:
    int singleNumber(vector<int>& nums) {
                
        int n = nums.size();
        int third = 0;
        int tmp;
        for (int i = 1; i<n; i++) {
            // nums[i-1] ^ nums[i] : XOR (XOR for every elements -> only bits which appear odd times remain 
            // | ( nums[i-1] & nums[i] & (~third) ) : set bit 1 for bits that is unset this time so that bit thirdly appeared will be removed.
            // bit that seeks thirdly appeared bit is masked on variable 'third'.
            // then bits that occur 3n times will not affect result bit
            tmp = third;
            third ^= (nums[i - 1] & nums[i]);
            nums[i] = (nums[i - 1] ^ nums[i]) | ((nums[i - 1] & nums[i]) & (~tmp));
        }
        return nums[n - 1];
    }
};

#else

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();
        int third = 0;
        for (int i = 1; i < n; i++) {
            //same alogirhtm with above
            third = nums[0] & (third ^ nums[i]);
            nums[0] = third | (nums[0] ^ nums[i]);
        }
        return nums[0];
    }
};



#endif


int main()
{
    Solution sol;

    int ret;
    vector<int> in = vector<int>({2,2,3,2});

    ret = sol.singleNumber(in);

    in = vector<int>({ 0,1,0,1,0,1,99});
    ret = sol.singleNumber(in);

    in = vector<int>({ -2,-2,-2 });
    ret = sol.singleNumber(in);

    return 0;
}
