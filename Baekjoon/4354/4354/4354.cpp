#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> getf(string str) {

    int len = str.length();
    vector<int> ret(len, 0);
        
    int acc = 0;
    for (int i = 1; i < len; i++) {
        while (acc > 0 && str[i] != str[acc]) {
            acc = ret[acc-1];
        }
        if (str[i] == str[acc]) {
            ret[i] = ++acc;
        }
    }

    return ret;

}

int partition(string str, vector<int>& pi) {

    
    int len = str.length();

    /*
    stack<int> cand;

    int ret = 1;
    
    int j = len;
    
    while (j > 0) {
        cand.push(j);
        j = pi[j-1];       
    }

    int cur;
    while (!cand.empty()) {
        cur = cand.top();
        cand.pop();
        if (len % cur != 0) continue;
        
        if (pi[len - 1] + cur == len) {
            ret = len/cur;
            break;
        }
    }
    */
    int ret = 1;
    if (str.length() % (str.length() - pi[len - 1]) == 0) {
        ret = str.length() / (str.length() - pi[len - 1]);
    }
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string in;
    
    while (getline(cin, in)) {
        if (in == ".") break;
        vector<int> pi = getf(in);
        printf("%d\n", partition(in, pi));
    }

    return 0;
}
