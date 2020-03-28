#include <iostream>
#include <vector>
#include <algorithm>
#define INTMAX 0x7FFFFFFF

using namespace std;

vector<int> dp;

void backtrack(int N) {
    printf("%d ", N);
    if (N == 1) return;
    
    int& ret = dp[N];
    if ((N % 3 == 0) && (dp[N / 3] == (ret - 1))) backtrack(N / 3);
    else if ((N % 2 == 0) && (dp[N / 2] == (ret - 1))) backtrack(N / 2);
    else backtrack(N - 1);
}


int main()
{
    int N;
    cin >> N;

    dp = vector<int>(N+1, INTMAX);
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        int& ret = dp[i];
        if (i % 3 == 0) ret = min(ret, dp[i / 3]+1);
        if (i % 2 == 0) ret = min(ret, dp[i / 2]+1);
        ret = min(ret, dp[i - 1]+1);
    }

    printf("%d\n", dp[N]);

    backtrack(N);

    return 0;
}