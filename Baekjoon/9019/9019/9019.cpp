#include <iostream>
#include <queue>
#define MOD 10000
#define sMOD 1000

using namespace std;

typedef int (*calcf)(int);

int D(int n) {
    return (2 * n) % MOD;
}
int S(int n) {
    return (n + (MOD - 1)) % MOD;
}
int L(int n) {
    return (n * 10) % MOD + n / sMOD;
}
int R(int n) {
    return (n % 10) * sMOD + n / 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    
    calcf calc[4] = {D, S, L, R};
    char calcchar[4] = { 'D', 'S', 'L', 'R' };


    int idx = 0;
    int A, B;
    while (idx < T) {
        cin >> A >> B;
        queue<pair<int,int>> q;
        vector<int> preidx(MOD, -1);
        vector<char> precalc(MOD, 'E');

        q.push(make_pair(A, 0));

        int cur = A;
        int cnt = 0;
        while (!q.empty()){
            cur = q.front().first;
            cnt = q.front().second;
            q.pop();

            if (cur == B) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int res = calc[i](cur);
                if (preidx[res] == -1) {
                    q.push(make_pair(res, cnt + 1));
                    preidx[res] = cur;
                    precalc[res] = calcchar[i];
                }
            }
        }

        vector<char> st;
        while (cur != A) {
            st.push_back(precalc[cur]);
            cur = preidx[cur];
        }
        
        for (auto it = st.rbegin(); it != st.rend(); it++) {
            printf("%c", *it);
        }
        
        printf("\n");
        idx++;
    }

    return 0;
}
