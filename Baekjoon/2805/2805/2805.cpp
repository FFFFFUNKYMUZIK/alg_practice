#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(vector<int>& len, int num, int cutlen) {

    long long acc = 0;
    for (int i = len.size() - 1; i >= 0; i--) {
        acc += (len[i] - cutlen);
        if (acc >= num) return true;
        if (len[i] <= cutlen) break;
    }

    return false;
}

int binsearch(vector<int>& len, int num) {
    int size = len.size();

    int s = 0, e = len[size - 1] - 1;
    int ret = 0;

    while (s <= e) {
        int mid = (s + e) / 2;

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

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;

    vector<int> arr(N, 0);
    int idx = 0;
    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    sort(arr.begin(), arr.end());

    printf("%d\n", binsearch(arr, M));

    return 0;
}
