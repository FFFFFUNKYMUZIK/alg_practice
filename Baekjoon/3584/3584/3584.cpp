#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;

    cin >> T;

    int idx = 0;
    while (idx < T) {
        cin >> N;

        vector<int> p(N+1, 0);
        vector<int> visit(N + 1, 0);
        int A, B;
        int idx2 = 1;
        while (idx2 < N) {
            cin >> A >> B;
            p[B] = A;
            idx2++;
        }
        int t1, t2;
        cin>>t1>>t2;
        while (t1 != 0) {
            visit[t1] = 1;
            t1 = p[t1];
        }
        while (p[t2] != 0 && visit[t2] == 0) {
            t2 = p[t2];
        }

        printf("%d\n", t2);

        idx++;
    }

    return 0;
}
