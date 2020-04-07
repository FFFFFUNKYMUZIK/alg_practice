#include <iostream>
#include <vector>

using namespace std;

#if 0
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        
        int lh = -1, rh = -1;
        int max_area = 0;
        int cur_area = 0;

        while (i < j) {
            if (lh < height[i]) {
                if (rh < height[j]) {
                    int part_height;

                    if (height[j] <= height[i]) {
                        rh = height[j];
                        part_height = height[j];
                    }
                    else {
                        lh = height[i];
                        part_height = height[i];
                    }

                    cur_area = (j - i) * part_height;
                    if (cur_area > max_area) max_area = cur_area;

                }
                else {
                    j--; continue;
                }
            }
            else {
                i++; continue;
            }
        }

        return max_area;

    }
};

#else

#include <algorithm>

//reference sol
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            res = max(res, (j - i) * min(height[i], height[j]));
            if (height[i] <= height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return res;
    }
};

#endif

int main()
{
    Solution sol;

    vector<int> input;
    
    int ret;

    input = vector<int>({ 1,8,6,2,5,4,8,3,7 });
    ret = sol.maxArea(input);
    input = vector<int>({ 1, 2 });
    ret = sol.maxArea(input);

    return 0;
}
