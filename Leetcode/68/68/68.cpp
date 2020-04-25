#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int acc = 0;
        
        vector<string> ret;
        vector<string> buf;
        for (int i = 0; i < words.size(); i++) {
            if (acc + words[i].length()+ buf.size() > maxWidth) {
                string nline;
                int tot_space = maxWidth - acc;
                if (buf.size() > 1) {
                    int each_space = tot_space / (buf.size() - 1);
                    int residual = tot_space % (buf.size() - 1);
                    vector<int> space(buf.size() - 1, each_space);
                    int cnt = 0;
                    while (cnt < residual) {
                        space[cnt++]++;
                    }

                    for (cnt = 0; cnt < buf.size() - 1; cnt++) {
                        nline += buf[cnt] + string(space[cnt], ' ');
                    }
                    nline += buf[cnt];
                }
                else { // buf.size()==1
                    nline += buf[0];
                    nline += string(tot_space, ' ');
                }
                ret.push_back(nline);


                acc = 0;
                vector<string>().swap(buf);
            }
            acc += words[i].length();
            buf.push_back(words[i]);
        }

        string nline;
        int i = 0;
        acc = 0;
        for (i = 0; i < buf.size() - 1; i++) {
            nline += buf[i] + string(" ");
            acc += buf[i].length() + 1;
        }
        nline += buf[i];
        acc += buf[i].length();

        while (acc++ < maxWidth) {
            nline += " ";
        }
        ret.push_back(nline);

        return ret;
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
    ret = sol.fullJustify(in, 20);


    return 0;
}
