#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int rx = x;
        int len = 0;
        while (rx > 0) { rx /= 10; len++; }
        rx = x;
        int idx = 0;
        int mid = (len + 1) / 2;

        stack<int> st;
        while (idx<mid){
            st.push(rx % 10);
            rx = rx / 10;
            idx++;
        }
        if (len % 2 != 0) st.pop();

        while (idx < len) {
            if (st.top() != rx % 10) {
                return false;
            }
            rx = rx / 10;
            st.pop();
            idx++;
        }

        return true;
    }
};


int main()
{
    Solution sol;

    bool ret;
    ret = sol.isPalindrome(121);
    ret = sol.isPalindrome(-121);
    ret = sol.isPalindrome(10);

    return 0;
}