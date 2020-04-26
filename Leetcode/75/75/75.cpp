#include <iostream>
#include <vector>

using namespace std;

#if 0
//red(0)-white(1)-blue(2)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //counting sort
        vector<int> cnt(3, 0);

        for (int i = 0; i < nums.size(); i++) cnt[nums[i]]++;
        for (int i = 0, idx = 0; i < cnt.size(); i++) {
            for (int j = 0; j < cnt[i]; j++) {
                nums[idx++] = i;
            }
        }
    }
};

#else

//one-pass algorithm
/*
In computing, a one-pass algorithm is a streaming algorithm which reads its input EXACTLY ONCE, IN ORDER, WITHOUT unbounded buffering.
A one-pass algorithm generally requires O(n) (see 'big O' notation) time and less than O(n) storage (typically O(1)), where n is the size of the input.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> idx(2, 0);
        idx[0] = 0; idx[1] = nums.size() - 1;
        while (idx[0] < nums.size() && nums[idx[0]] == 0) idx[0]++;
        while (idx[1] >= 0 && nums[idx[1]] == 2) idx[1]--;

        int tmp;
#define SWAP(i, j) tmp = nums[i]; \
                 nums[i] = nums[j]; \
                 nums[j] = tmp;

        int i = idx[0];
        while (i <= idx[1]) {
            switch (nums[i]) {
                case 0:
                    SWAP(i, idx[0]);
                    i++; idx[0]++;
                    break;
                case 2:
                    SWAP(i, idx[1]);
                    idx[1]--;
                    break;
                default:
                    i++;
                    break;
            }
        }
        
    }
};

#endif

int main()
{
    Solution sol;
    vector<int> in;


    in = vector<int>({ 2,0,2,1,1,0 });
    sol.sortColors(in);

    in = vector<int>({ 1,2,2,2,2,0,0,0,1,1 });
    sol.sortColors(in);


    in = vector<int>({ 0 });
    sol.sortColors(in);
    return 0;
}
