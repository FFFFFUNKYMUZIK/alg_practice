#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

#if 0

//leetcode solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        if (n <= 1) return 0;

        int maxlen = 0;
        int len = 0;

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else{
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    int pre = st.top();
                    len = i - pre;
                    if (maxlen < len) maxlen = len;
                }
            }
        }

        return maxlen;

    }
};


#elif 0

//DP
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        if (n <= 1) return 0;

        int maxlen = 0;
        vector<int> dp(n+1, 0);

        for (int i = 1, j = i+1; i < n; i++, j++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    //...()
                    dp[j] = dp[j - 2] + 2;
                }
                else {
                    //..((..))
                    if ((i - dp[j - 1] - 1)>= 0 && s[i - dp[j - 1] - 1] == '(') {
                        dp[j] = dp[j - 1] + 2 + dp[j - dp[j - 1] - 2];
                    }
                }
            }
            else {
                continue;
            }
        }

        for (int j = 1; j <= n; j++) {
            if (maxlen < dp[j]) maxlen = dp[j];
        }

        return maxlen;

    }
};

#else

//leetcode solution
class Solution {
public:
    int longestValidParentheses(string s) {

        int left = 0, right = 0, maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i]== '(') {
                left++;
            }
            else {
                right++;
            }
            if (left == right && maxlen < 2*right) {
                maxlen = 2 * right;
            }
            else if (right >= left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }
            if (left == right && maxlen < 2 * right) {
                maxlen = 2 * right;
            }
            else if (left >= right) {
                left = right = 0;
            }
        }

        
        return maxlen;
    }
};


#endif



int main()
{
    Solution sol;

    string in;
    int ret;


    in = string("())");
    ret = sol.longestValidParentheses(in);

    in = string("(()");
    ret = sol.longestValidParentheses(in);

    in = string("((()())()()(()");
    ret = sol.longestValidParentheses(in);

    in = string(")(()))()(()))");
    ret = sol.longestValidParentheses(in);

    in = string("()(()");
    ret = sol.longestValidParentheses(in);

    in = string("()(())");
    ret = sol.longestValidParentheses(in);

    in = string("()(((()))");
    ret = sol.longestValidParentheses(in);

    in = string("(()(((()");
    ret = sol.longestValidParentheses(in);

    in = string("((()())");
    ret = sol.longestValidParentheses(in);


    return 0;
}
