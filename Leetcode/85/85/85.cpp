#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:

    int getrowmaxArea(vector<int>& row) {
        int n = row.size();

        row.push_back(0);
        stack<int> st;
        st.push(-1);
        st.push(0);

        int maxArea = 0;

        for (int i = 1; i <= n; i++) {
            int cheight = row[i];
            while (st.top() != -1 && row[st.top()] >= cheight) {
                int rheight = row[st.top()];
                st.pop();
                int s = st.top();
                int cArea = (i - s - 1) * rheight;
                maxArea = max(cArea, maxArea);
            }
            st.push(i);
        }

        row.pop_back();

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<int> accum(n, 0);

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') accum[j] = 0;
                else accum[j]++;
            }
            maxArea = max(maxArea, getrowmaxArea(accum));
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;
    int ret;

    vector<vector<char>> in;
    in = vector<vector<char>>({ {'1','0','1','0','0'}, {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}, });
    ret = sol.maximalRectangle(in);

    return 0;
}