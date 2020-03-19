#include <iostream>

using namespace std;

int psum[100001];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int N, M;
    cin >> N >> M;
    int idx = 0;

    int cur;
    int cur_sum=0;
    while (idx < N) {
        cin >> cur;
        cur_sum += cur;
        psum[idx+1] = cur_sum;
        idx++;
    }

    idx = 0;
    int l, r;
    while (idx < M) {
        cin >> l >> r;
        cout<< psum[r] - psum[l-1] <<'\n';
        idx++;
    }

    return 0;
}
