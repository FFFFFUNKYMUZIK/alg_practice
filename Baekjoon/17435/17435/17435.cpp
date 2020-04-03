#include <iostream>
#include <vector>

/*

using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int m;
    cin >> m;
    vector<int> arr(m+1, 0);

    int idx = 1;
    while (idx <= m) {
        cin >> arr[idx];
        idx++;
    }
    int q;
    cin >> q;

    idx = 1;
    int n, x;
    while (idx <= q) {
        cin >> n >> x;
        while (n-- > 0) {
            x = arr[x];
        }
        printf("%d\n", x);
        idx++;
    }


    return 0;
}


*/

#include <cmath>

using namespace std;


#define MAX_N 500000

//sparse table
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> m;

    int logsize = (int)log2(MAX_N);
    vector<vector<int>> tb(m + 1, vector<int>(logsize + 1, 0));

    int idx = 1;
    while (idx <= m) {
        cin >> tb[idx][0];
        idx++;
    }

    //make table
    //table[i][j] = table[table[i][j-1]][j-1];
    //O(mlog(max(n))
    for (int j = 1; j <= logsize; j++) {
        for (int i = 1; i <= m; i++) {
            tb[i][j] = tb[tb[i][j - 1]][j - 1];
        }
    }

    int q;
    cin >> q;

    idx = 1;
    int n, x;
    while (idx <= q) {
        cin >> n >> x;
        while (n>0) {
            int log2val = (int)log2(n);
            x = tb[x][log2val];
            n -= (1<<log2val);
        }

        printf("%d\n", x);
        idx++;
    }



    return 0;
}