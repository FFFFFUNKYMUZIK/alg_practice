#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(vector<int>& len, int num, int cutlen) {

    int acc = 0;
    for (int i = len.size() - 1; i >= 0; i--) {
        acc += len[i] / cutlen;
        if (acc >= num) return true;
        if (len[i] < cutlen) break;
    }

    return false;
}

int binsearch(vector<int> & len, int num) {
    int size = len.size();

    long long s = 1, e = len[size-1];
    int ret = 0;

    while (s <= e) {
        long long mid = (s + e) / 2;

        if (valid(len, num, mid)) {
            s = mid + 1;
            ret = mid;
        }
        else {
            e = mid - 1;
        }
    }

    return ret;
}

int main()
{
    int K, N;

    cin >> K >> N;

    vector<int> arr(K, 0);
    int idx = 0;
    while (idx < K) {
        cin >> arr[idx];
        idx++;
    }

    sort(arr.begin(), arr.end());

    printf("%d\n", binsearch(arr, N));

    return 0;
}
