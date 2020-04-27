#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if (n == 0) return 0;

        int maxArea = 0;
        heights.push_back(0);
        stack<int> st;
        st.push(-1);
        st.push(0);

        for (int i = 1; i <= n; i++) {
            int cheight = heights[i];
            while ((st.top() != -1) && heights[st.top()] >= cheight) {
                int rheight = heights[st.top()];
                st.pop();
                int s = st.top();
                int cArea = (i - s - 1) * rheight;
                maxArea = max(cArea, maxArea);
            }
            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }
};


int main()
{
    Solution sol;

    int ret;
    vector<int> in;

    in = vector<int>({2,1,5,6,2,3});
    ret = sol.largestRectangleArea(in);

    return 0;
}
