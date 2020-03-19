#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int idx = 0;
    while (idx < T) {
        int N, M;
        cin >> N >> M;
        int idx2 = 0;
        int a, b;
        while (idx2 < M) {
            cin >> a >> b;
            idx2++;
        }
        cout << N - 1 << endl;
        idx++;
    }

    

    return 0;
}
