#include <iostream>

using namespace std;

int main()
{
    unsigned long long N, P;

    cin >> N >> P;

    unsigned long long ret = 1;
    int i;
    for (i = 2; i <= N; i++) {
        ret = (ret * i);
        if (ret > P) break;
    }

    unsigned long long test = ret % P;

       
    cout << ret << '\n';
}