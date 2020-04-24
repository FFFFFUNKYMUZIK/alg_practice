#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

    }
};

int main()
{

    Solution sol;
    vector<string> ret;

    vector<string> in;

    in = vector<string>({string("This"), string("is"),  string("an"),  string("example"),  string("of"),  string("text"),  string("justification."), });
    ret = sol.fullJustify(in, 16);

    in = vector<string>({ string("What"), string("must"),  string("be"),  string("acknowledgement"),  string("shall"),  string("be") });
    ret = sol.fullJustify(in, 16);

    in = vector<string>({ string("Science"), string("is"),  string("what"),  string("we"),  string("understand"),  string("well"), string("enough"), string("to"), string("explain"), string("to"),
                        string("a"), string("computer."), string("Art"), string("is"), string("everything"), string("else"), string("we"), string("do") });
    sol.fullJustify(in, 16);


    return 0;
}
