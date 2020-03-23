#include <iostream>
#define SIDE 1024

using namespace std;

int table[SIDE +1][SIDE + 1];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N>>M;

    int idx = 1;

    while (idx <= N) {
        int idx2 = 1;

        int val;
        int row_acc = 0;
        while (idx2 <= N) {
            cin >> val;
            row_acc += val;
            table[idx][idx2] = row_acc + table[idx - 1][idx2];

            idx2++;
        }
        idx++;
    }

    idx = 0;
    int x1, y1, x2, y2;
    while (idx < M) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        printf("%d\n", table[x2][y2] - table[x2][y1] - table[x1][y2] + table[x1][y1]);
        idx++;
    }

    return 0;
}
