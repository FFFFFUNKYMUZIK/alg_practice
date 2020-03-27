#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VAL 360000

using namespace std;

vector<int> getpi(vector<int>& arr) {

    vector<int> ret(arr.size(), 0);

    int acc = 0;
    for (int i = 1; i < arr.size(); i++) {
        while (acc > 0 && arr[i] != arr[acc]) {
            acc = ret[acc - 1];
        }
        if (arr[i] == arr[acc]) {
            ret[i] = ++acc;
        }
    }

    return ret;
}

bool compare(vector<int>& a, vector<int>& b, vector<int>& pb) {

    bool ret = false;
    int len = a.size();

    int acc = 0;
    int idx = 0;
    int rot = 0;

     while((rot == 0) || (idx - acc < 0) ){
        while (acc > 0 && a[idx] != b[acc]) {
            acc = pb[acc - 1];
        }
        
        if (a[idx] == b[acc]) {
            acc++;
        }
        idx++;

        if (idx == len) {
            idx = 0;
            rot = 1;
        }
        if (acc == len) {
            ret = true;
            break;
        }
     }
     return ret;
}

int main()
{
    int N;
    cin >> N;
    
    vector<int> a(N, 0), b(N, 0);
    vector<int> adiff(N, 0), bdiff(N, 0);

    int min;
    int idx = 0;

    while (idx < N) {
        cin >> a[idx];
        idx++;
    }

    idx = 0;
    while (idx < N) {
        cin >> b[idx];
        idx++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < N; i++) {
        adiff[i] = (a[(i + 1) % N] - a[i] + MAX_VAL) % MAX_VAL;
        bdiff[i] = (b[(i + 1) % N] - b[i] + MAX_VAL) % MAX_VAL;
    }

    vector<int> bp = getpi(bdiff);

    if (compare(adiff, bdiff, bp)) {
        printf("%s\n", "possible");
    }
    else {
        printf("%s\n", "impossible");
    }

    return 0;
}
