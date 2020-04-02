#include <iostream>
#include <vector>
#define LENGTH 100001

using namespace std;

/*

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int N, K;

    cin >> N >> K;

    vector<int> st;
    st.reserve(LENGTH);
    int cnt = -1;

    if (N > K) {
        cnt = N - K;
        for (int i = K; i <= N; i++) {
            st.push_back(i);
        }
    }
    else{

        vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(LENGTH, 0));
        vector<int> preidx = vector<int>(LENGTH, -1);

        int tictoc = 0;

        bool find = false;

        dp[0][N] = 1;

        while (!find) {

            cnt++;

            for (int i = 0; i < LENGTH; i++) {
                if (dp[tictoc][i] != 0) {
                    if (i == K) {
                        find = true;
                        break;
                    }
                    if (i > 0 && preidx[i - 1] == -1) {
                        dp[1 - tictoc][i - 1] = 1;
                        preidx[i - 1] = i;
                    }
                    if (i < LENGTH - 1 && preidx[i + 1] == -1) {
                        dp[1 - tictoc][i + 1] = 1;
                        preidx[i + 1] = i;
                    }
                    if (2 * i < LENGTH && preidx[2 * i] == -1) {
                        dp[1 - tictoc][2 * i] = 1;
                        preidx[2 * i] = i;
                    }
                    dp[tictoc][i] = 0;
                }
            }

            tictoc = 1 - tictoc;
        }

        int track = K;

        while (track != N) {
            st.push_back(track);
            track = preidx[track];
        }
        st.push_back(N);
    }

    printf("%d\n", cnt);

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        printf("%d ", *it);
    }

    return 0;
}
*/



//bfs
#include <queue>

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;

    cin >> N >> K;

    queue<pair<int, int>> q;

    vector<int> preidx(LENGTH, -1);

    q.push(make_pair(N, 0));

    int cnt = 0;
    while (!q.empty()) {
        int pos = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (pos == K) {
            cnt = dist;
            break;
        }

        if (pos > 0 && preidx[pos - 1] == -1) {
            q.push(make_pair(pos - 1, dist + 1));
            preidx[pos-1] = pos;
        }
        if (pos < (LENGTH - 1) && preidx[pos + 1] == -1) {
            q.push(make_pair(pos + 1, dist + 1));
            preidx[pos + 1] = pos;
        }
        if (2 * pos < LENGTH && preidx[2 * pos] == -1) {
            q.push(make_pair(2 * pos, dist + 1));
            preidx[2 * pos] = pos;
        }
    }

    int track = K;
    vector<int> st;

    while (track != N) {
        st.push_back(track);
        track = preidx[track];
    }
    st.push_back(N);

    printf("%d\n", cnt);

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        printf("%d ", *it);
    }

    return 0;
}