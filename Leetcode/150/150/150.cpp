#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

    }
};

int main()
{
    Solution sol;
    vector<string> in;
    int ret;

    in = vector<string>({ string("2"), string("1") , string("+") , string("3") , string("*") });
    ret = sol.evalRPN(in);

    in = vector<string>({ string("4"), string("13") , string("5") , string("/") , string("+") });
    ret = sol.evalRPN(in);

    in = vector<string>({ string("10"), string("6") , string("9") , string("3") , string("+"), string("-11"), string("*"), string("/"), string("*"), string("17"), string("+"), string("5"), string("+") });
    ret = sol.evalRPN(in);


    return 0;
}


int main()
{

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

