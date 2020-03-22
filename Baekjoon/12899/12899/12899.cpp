#include <iostream>
#include <vector>
#include <cmath>

#define MAX_ELEMENT 2000000

using namespace std;

void update(vector<int>& tree, int s, int e, int idx, int val) {

    if (val<s || e<val) {
        return;
    }

    tree[idx]++;

    if (s!=e){
        int mid = (s + e) / 2;
        update(tree, s, mid, 2 * idx, val);
        update(tree, mid+1, e, 2 * idx + 1, val);
    }

}

int get_n_remove(vector<int>& tree, int s, int e, int idx, int X) {

    tree[idx]--;
    if (s == e) return s;

    int mid = (s + e) / 2;
    int ln = tree[2 * idx];
    if (X <= ln) {
        return get_n_remove(tree, s, mid, 2 * idx, X);
    }
    else {
        return get_n_remove(tree, mid + 1, e, 2 * idx + 1, X-ln);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int h = ceil(log2(MAX_ELEMENT + 1)) + 1;

    vector<int> tree((1 << h + 1) + 1, 0);
 
    int idx = 0;
    int T, X;
    while (idx < N) {
        cin >> T >> X;
        if (T == 1) {
            update(tree, 1, MAX_ELEMENT, 1, X);
        }
        else if (T == 2) {
            printf("%d\n", get_n_remove(tree, 1, MAX_ELEMENT, 1, X));
        }

        idx++;
    }

    return 0;
}
