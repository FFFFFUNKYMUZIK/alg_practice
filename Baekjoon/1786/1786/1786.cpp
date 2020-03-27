#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getpi(string str, vector<int>& pi) {
    if (pi.size() < str.length()) pi.resize(str.length());

    int acc = 0;
    for (int i = 1; i < str.length(); i++) {
        while (acc > 0 && str[i] != str[acc]) {
            acc = pi[acc - 1];
        }
        if (str[i] == str[acc]) {
            pi[i] = ++acc;
        }
    }
}

vector<int> kmp(string t, string p, vector<int>& pip) {

    int i = 0, j = 0;
    vector<int> pos;
    int start = 0;

    while (i < t.length()) {

        while (j > 0 && t[i] != p[j]) {
            j = pip[j - 1];
            start = i - j;
        }
        if (t[i] == p[j]) {
            if (j == 0) start = i;
            j++;
        }

        if (j >= p.length()) {
            pos.push_back(start+1);
            j = pip[j - 1];
            start = i + 1 - j;
        }
        i++;
    }

    return pos;

}

int main()
{
    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> pi_P(P.size(), 0);

    getpi(P, pi_P);

    vector<int> ret = kmp(T, P, pi_P);

    printf("%d\n", ret.size());
    for (int i = 0; i < ret.size(); i++) {
        printf("%d\n", ret[i]);
    }


    return 0;
}
