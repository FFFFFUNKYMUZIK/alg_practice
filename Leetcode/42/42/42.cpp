#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        stack<int> st;

        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int pre = 0;
            while (!st.empty() && height[st.top()] <= height[i]) {
                water += (i - st.top() - 1) * (height[st.top()] - pre);
                pre = height[st.top()];
                st.pop();
            }
            if (!st.empty()) {
                water += (i - st.top() - 1) * (height[i] - pre);
            }
            st.push(i);
        }

        return water;
    }
};

int main()
{
    Solution sol;
    int ret;
    vector<int> in;

    in = vector<int>({ 0,1,0,2,1,0,1,3,2,1,2,1 });
    ret = sol.trap(in);

    in = vector<int>({ 0, 8, 9, 2, 4, 6, 1, 3, 5, 7, 45, 73, 7623, 24, });
    ret = sol.trap(in); 


    return 0;
}