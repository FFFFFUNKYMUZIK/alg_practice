#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char cur = s[i];
            if (cur == '(' || cur == '[' || cur == '{') st.push(cur);
            else {
                if (st.empty()) return false;
                switch (cur) {
                case ')':
                    if (st.top() != '(') return false;
                    break;
                case ']':
                    if (st.top() != '[') return false;
                    break;
                case '}':
                    if (st.top() != '{') return false;
                    break;
                default :
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty()) return false;

        return true;
    }
};

int main()
{
    return 0;
}
