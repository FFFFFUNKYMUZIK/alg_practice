#include "stdafx.h"
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {

	int plus(int a, int b) { return a + b; };
	int minus(int a, int b) { return a - b; };
	int mult(int a, int b) { return a * b; };
	int div(int a, int b) { return a / b; };

public:

	int (Solution::*farr[4])(int, int);

	void setFunc() {
		
		farr[0] = &Solution::plus;
		farr[1] = &Solution::minus;
		farr[2] = &Solution::mult;
		farr[3] = &Solution::div;
		
	}

	int evalRPN(vector<string>& tokens) {
		int n = tokens.size();
		stack<int> st;
		string cur;
		string ops = "+-*/";
		setFunc();

		for (int i = 0; i < n; i++) {		
			cur = tokens[i];
			int op1, op2, num;
			if ((num = ops.find(cur)) != string::npos) {
				op1 = st.top();
				st.pop();
				op2 = st.top();
				st.pop();
				st.push((this->*farr[num])(op2, op1));
			}
			else {
				st.push(stoi(cur));
			}
		}

		return st.top();
	}
};


int main()
{
	Solution sol;
	vector<string> in;
	int ret;

	in = vector<string>({string("2"), string("1") , string("+") , string("3") , string("*") });
	ret = sol.evalRPN(in);

	in = vector<string>({ string("4"), string("13") , string("5") , string("/") , string("+") });
	ret = sol.evalRPN(in);

	in = vector<string>({ string("10"), string("6") , string("9") , string("3") , string("+"), string("-11"), string("*"), string("/"), string("*"), string("17"), string("+"), string("5"), string("+") });
	ret = sol.evalRPN(in);

    return 0;
}

