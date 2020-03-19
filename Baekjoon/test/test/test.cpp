#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string formula;
    cin>>formula;

    int pos = 0;
    string val;
    int ret = 0;
    int status = 1;

    for (int i = 0; i < formula.length(); i++) {
        if (formula[i] == '+') {
            val = formula.substr(pos, i - pos);
            ret += stoi(val) * status;
            pos = i + 1;
        }
        if (formula[i] == '-') {
            val = formula.substr(pos, i - pos);
            ret += stoi(val) * status;
            pos = i + 1;
            status = -1;
        }
    }

    val = formula.substr(pos, formula.length() - pos);
    ret += stoi(val) * status;

    cout << ret << endl;

    return 0;
}