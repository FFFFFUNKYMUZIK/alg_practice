#include <iostream>
#include <vector>

using namespace std;

/*
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 1);

        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i-1; j >= 1; j--) {
                ret[j] += ret[j - 1];
            }
        }

        return ret;
    }
};



int main()
{
    Solution sol;

    vector<int> ret;

    ret = sol.getRow(3);

    ret = sol.getRow(5);

    return 0;
}
