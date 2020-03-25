#include <iostream>
#include <vector>

using namespace std;

typedef struct minmax_t {
    int minval;
    int maxval;
} minmax;

vector<int> arr;
vector<int> op;

minmax calculate(int idx, int val) {

    if (idx == arr.size()) return { val, val };

    vector<minmax> out;

    if (op[0] > 0) {
        op[0]--;
        out.push_back(calculate(idx + 1, val + arr[idx]));
        op[0]++;
    }
    if (op[1] > 0) {
        op[1]--;
        out.push_back(calculate(idx + 1, val - arr[idx]));
        op[1]++;
    }
    if (op[2] > 0) {
        op[2]--;
        out.push_back(calculate(idx + 1, val * arr[idx]));
        op[2]++;
    }
    if (op[3] > 0) {
        op[3]--;
        out.push_back(calculate(idx + 1, val / arr[idx]));
        op[3]++;
    }

    minmax minmaxout;
    minmaxout.minval = out[0].minval;
    minmaxout.maxval = out[0].maxval;

    for (int i = 1; i < out.size(); i++) {
        if (out[i].minval < minmaxout.minval) {
            minmaxout.minval = out[i].minval;
        }
        if (out[i].maxval > minmaxout.maxval) {
            minmaxout.maxval = out[i].maxval;
        }
    }

    return minmaxout;
}

int main()
{
    int N;
    
    cin >> N;

    arr = vector<int>(N, 0);
    op = vector<int>(4, 0);

    int val;
    int idx = 0;
    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    idx = 0;
    while (idx < 4) {
        cin >> op[idx];
        idx++;
    }

    minmax out = calculate(1, arr[0]);

    printf("%d\n%d", out.maxval, out.minval);

    return 0;
}