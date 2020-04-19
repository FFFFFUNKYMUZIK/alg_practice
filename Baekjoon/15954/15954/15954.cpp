#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{

    int N, K;

    cin >> N >> K;

    int idx = 0;
    vector<ll> pr(N, 0);
    while (idx < N) {
        cin >> pr[idx];
        idx++;
    }

    vector<ll> psum(N + 1, 0);
    vector<ll> pssum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + pr[i];
        pssum[i + 1] = pssum[i] + pr[i]*pr[i];
    }

    ld stdev, mean;
    ld min_stdev = numeric_limits<long double>::max();
    for (int i = 0; i < N - K + 1; i++) {
        for (int j = i + K - 1; j < N; j++) {
            mean = (psum[j + 1] - psum[i]) / (ld)(j-i+1);
            stdev = sqrt((pssum[j + 1] - pssum[i]) / (ld)(j - i + 1) - mean * mean);
            if (stdev < min_stdev) min_stdev = stdev;
        }
    }

    printf("%.11LF", min_stdev);

    return 0;
}
