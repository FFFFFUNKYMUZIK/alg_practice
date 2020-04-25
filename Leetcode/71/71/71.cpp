#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        string ret;
        stack<string> st;
        string dir;
        path += "/";

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/'){
                if (dir != "") {
                    if (dir == "..") {
                        if (!st.empty()) st.pop();
                    }
                    else if (dir == ".") {
                        //NOP
                    }
                    else {
                        st.push(dir);

                    }
                    dir = "";
                
                }
            }
            else {
                dir += path[i];
            }
        }

        if (st.empty()) return string("/");
        while (!st.empty()) {
            ret = "/" + st.top() + ret;
            st.pop();
        }


        return ret;
    }
};

int main()
{
    Solution sol;

    string path;
    string ret;

    path = string("/home/");
    ret = sol.simplifyPath(path);

    path = string("/../");
    ret = sol.simplifyPath(path);

    path = string("/home//foo/");
    ret = sol.simplifyPath(path);

    path = string("/a/./b/../../c/");
    ret = sol.simplifyPath(path);

    path = string("/a/../../b/../c//.//");
    ret = sol.simplifyPath(path);

    path = string("/a//b////c/d//././/..");
    ret = sol.simplifyPath(path);

    path = string("/.");
    ret = sol.simplifyPath(path);

    path = string("/...");
    ret = sol.simplifyPath(path);

    return 0;
}