#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getpi(string str) {

    int len = str.length();
    vector<int> ret(len, 0);

    int acc = 0;
    for (int i = 1; i < len; i++) {
        while (acc > 0 && str[i] != str[acc]) {
            acc = ret[acc - 1];
        }
        if (str[i] == str[acc]) {
            ret[i] = ++acc;
        }
    }
    return ret;
}

int findshortest(string str, vector<int>& pi) {

    /*
    int len = str.length();
    int ret = len;
    int idx = len - 1;

    do {
        len = idx + 1;
        idx -= pi[idx];

        ret = idx + 1;
    } while (((len % (idx + 1)) == 0) && pi[idx] !=0);

    return ret;
    */

    return str.length() - pi[str.length() - 1];
}

int main()
{
    int len;
    string in;

    getline(cin, in);
    getline(cin, in);
    
    vector<int> pi = getpi(in);

    printf("%d\n", findshortest(in, pi));
       
    return 0;
 
}