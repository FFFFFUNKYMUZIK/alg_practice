#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(vector<int>& arr, int num, int dist) {

    num--;
    int latest = 0;
    for (int i = 1; i < arr.size()&& num>0; i++) {
        if (arr[i] - arr[latest] >= dist) {
            num--;
            latest = i;
        }
    }

    return (num == 0);
}


int binsearch(vector<int>& arr, int num) {

    int size = arr.size();

    int s = 1;
    int e = arr[size - 1] - arr[0];

    int ret;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (valid(arr, num, mid)) {
            ret = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return ret;
}


int main()
{
    int N, C;
    cin >> N>>C;

    vector<int> arr(N, 0);

    int idx = 0;
    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    sort(arr.begin(), arr.end());

    int ret = binsearch(arr, C);
    printf("%d\n", ret);

    return 0;
}
