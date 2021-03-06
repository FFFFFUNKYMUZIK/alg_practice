﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binsearch(vector<int>& arr, int size, int val) {
    int s = 0;
    int e = size-1;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] > val) {
            e = mid - 1;
        }
        else if (arr[mid] <val) {
            s = mid + 1 ;
        }
        else {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int N, M;

    cin >> N;
    vector<int> arr(N, 0);


    int idx = 0;
    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    sort(arr.begin(), arr.end());

    cin >> M;
    vector<int> query(M, 0);

    idx = 0;
    while (idx < M) {
        cin >> query[idx];
        idx++;
    }

    for (int i = 0; i < M; i++) {
        printf("%d\n", binsearch(arr, N, query[i]));
    }

    return 0;
}