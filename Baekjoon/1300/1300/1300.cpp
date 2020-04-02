#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, k;
    cin >> N >> k;

    int s = 1, e = k;

    int ret = 1;
    //O(N^2log(k))
    while (s <= e) {
        int cnt = 0;
        int mid = (s + e) / 2;

        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < k) {
            s = mid + 1;
        }
        else {
            ret = mid;
            e = mid - 1;
        }
    }

    printf("%d\n", ret);

    return 0;
}
