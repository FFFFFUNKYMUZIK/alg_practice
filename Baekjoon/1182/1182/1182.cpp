#include <iostream>

using namespace std;

int arr[20];

int main()
{
    int N, S;
    cin >> N >> S;

    int idx = 0;
    while (idx < N) {
        cin>>arr[idx];
        idx++;
    }
    
    int subset = (1 << N) - 1;

    int cur, sum;
    int cnt = 0;
    for (int i = 1; i <= subset; i++) {
        cur = i;
        idx = 0;
        sum = 0;
        while (cur != 0) {
            if (cur & 0x01) sum += arr[idx];
            idx++;
            cur >>= 1;
        }
        if (sum == S) cnt++;
    }
    
    cout << cnt << '\n';
    
    return 0;
}

