#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        vector<int> ret(n + 1, 0);

        int round = 1;
        for (int i = n - 1; i >= 0; i--) {
            digits[i] = digits[i] + round;
            round = digits[i] / 10;
            digits[i] = digits[i] % 10;
            ret[i + 1] = digits[i];
            if (round == 0) break;
        }
        if (round > 0) {
            ret[0] = 1;
            return ret;
        }

        return digits;
    }
};


int main()
{
    Solution sol;

    vector<int> in, ret;


    in = vector<int>({1,2,3});
    ret = sol.plusOne(in);

    in = vector<int>({ 4,3,2,1 });
    ret = sol.plusOne(in);

    in = vector<int>({ 0 });
    ret = sol.plusOne(in);

    in = vector<int>({ 9 });
    ret = sol.plusOne(in);

    in = vector<int>({ 1,9,9,9 });
    ret = sol.plusOne(in);

    in = vector<int>({ 9,9,9,9 });
    ret = sol.plusOne(in);
    return 0;
}
