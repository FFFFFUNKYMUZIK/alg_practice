#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        if (n == 0) return -1;

        int s=0, e=n-1;
        
        bool inorder;
        while (s <= e) {
            inorder = nums[s] <= nums[e];
            int mid = (s + e) / 2;
            if (!inorder) {
                if (nums[s] <= nums[mid]) {
                    if (nums[mid] < target) {
                        s = mid + 1;
                    }
                    else if (nums[mid] > target) {
                        if (target <= nums[e]) {
                            s = mid + 1;
                        }
                        else {
                            e = mid - 1;
                        }
                    }
                    else {
                        return mid;
                    }
                }
                else {
                    if (nums[mid] < target) {
                        if (target <= nums[e]) {
                            s = mid + 1;
                        }
                        else {
                            e = mid - 1;
                        }
                    }
                    else if (nums[mid] > target) {
                        e = mid - 1;
                    }
                    else {
                        return mid;
                    }

                }
            }
            else {
                if (nums[mid] < target) {
                    s = mid + 1;
                }
                else if (nums[mid] > target) {
                    e = mid - 1;
                }
                else{
                    return mid;
                }
            }

        }
        
        return -1;
    }
};


int main()
{
    Solution sol;
    
    int ret, tar;

    vector<int> in;

    in = vector<int>({ 4,5,6,7,0,1,2 });
    tar = 0;
    ret = sol.search(in, tar);

    in = vector<int>({ 4,5,6,7,0,1,2 });
    tar = 3;
    ret = sol.search(in, tar);

    in = vector<int>({ 6,7,9,10,11,15,17, 2, 4, 5 });
    tar = 17;
    ret = sol.search(in, tar);

    return 0;
}
