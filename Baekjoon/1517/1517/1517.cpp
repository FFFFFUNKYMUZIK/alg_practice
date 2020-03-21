#include <iostream>
#include <vector>

using namespace std;

unsigned long long swapcnt = 0;

void merge(vector<int>& arr, int s, int mid, int e) {

    vector<int> tmp(e - s + 1, 0);
    int tmpidx = 0;

    int l = s, r = mid + 1;

    while (l <= mid && r <= e) {
        if (arr[l] <= arr[r]) {
            tmp[tmpidx++] = arr[l++];
        }
        else {
            tmp[tmpidx++] = arr[r++];
            swapcnt+= (mid - l +1);
        }
    }

    while (l <= mid) {
        tmp[tmpidx++] = arr[l++];
    }
    while (r <= e) {
        tmp[tmpidx++] = arr[r++];
    }

    for (int i = 0; i < tmp.size(); i++) {
        arr[s++] = tmp[i];
    }

}

void merge_sort(vector<int>& arr, int s, int e) {

    if (s == e) return;

    int mid = (s + e) / 2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);

    merge(arr, s, mid, e);

}


int main()
{
    int N;

    cin >> N;
    int idx = 0;
    vector<int> arr(N, 0);

    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    merge_sort(arr, 0, N - 1);

    printf("%lld\n", swapcnt);

    return 0;
}