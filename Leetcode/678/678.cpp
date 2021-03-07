class Solution {
public:
    bool checkValidString(string s) {
       	int n = s.length();

       	/*
       	'(' : +1
		')' : -1
		'*' : -1, 0, 1
		*/

		int lb = 0, rb = 0;
		int st = 0;

		for (int i=0;i<s.length();i++){
			if (s[i]=='('){
				st++;
			}
			else if (s[i] == ')'){
				st--;
				if (st<0){
					if (rb>0){
						rb--;
						st = 0;
						lb = 0;
					}
					else
						return false;
				}

				lb = min(lb, st);
			}
			else{
				lb++;rb++;
				lb = min(lb, st);
			}
		}

		return st - lb <= 0;
    }
};