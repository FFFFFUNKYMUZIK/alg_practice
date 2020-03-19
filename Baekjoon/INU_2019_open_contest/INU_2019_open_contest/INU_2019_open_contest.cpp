// INU_2019_open_contest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*

//problem A
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int N;
    cin >> N;
    int idx = 0;
    unsigned int cur = 0;
    unsigned int min1 = 1<<32 -1, min2 = 1 << 32 - 1;

    while (cur != -1) {
        cin >> cur;
        if (cur != -1) {
            min1 = min(cur, min1);
        }
        idx++;
    }

    while (idx < N) {
        cin >> cur;
        min2 = min(cur, min2);
        idx++;
    }

    cout << min1 + min2 << endl;
    
    return 0;
}


*/

//Problem B
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    unsigned int K;
    cin >> N >> M >> K;
    unsigned int idx = 0, idx2 = 0;
    unsigned int cur = 0;
    unsigned int minidx2 = 1 << 32 - 1;
    unsigned int reach = 0;

    while (idx < N) {
        unsigned int distance = 0;
        while (idx2 < M) {

            cin >> cur;
            distance += cur;
            if (distance >= K) {
                if (idx2 < minidx2) {
                    reach = idx;
                    minidx2 = idx2;
                }
                while (idx2 < M-1) {
                    cin >> cur;
                    idx2++;
                }
            }
            idx2++;
        
        }
        idx2 = 0;
        idx++;
    }

    cout << reach + 1 << " " << minidx2 + 1<< endl;

    return 0;
}
*/


//Problem C
/*
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    unsigned int N, A, B;
    cin >> N >> A >> B;
    unsigned int idx = 0;
    unsigned int cur = 0;
    priority_queue<unsigned int> tilesmall, tilebig;

    while (idx < A) {
        cin >> cur;
        tilesmall.push(cur);
        idx++;
    }
    idx = 0;
    while (idx < B) {
        cin >> cur;
        tilebig.push(cur);
        idx++;
    }

    unsigned int length = 0;
    unsigned int pretty_sum = 0;

    if (N % 2 == 1) {
        N -= 1;
        pretty_sum += tilesmall.top();
        tilesmall.pop();
    }

    while (tilesmall.size() > 1) {
        unsigned int tmp = tilesmall.top();
        tilesmall.pop();
        tmp += tilesmall.top();
        tilesmall.pop();
        tilebig.push(tmp);
    }

    while (length < N) {
        pretty_sum += tilebig.top();
        tilebig.pop();
        length += 2;
    }
    cout << pretty_sum <<endl;
    return 0;
}
*/

//Problem D
/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
unsigned char map[2001][2001] = { 0, };
unsigned char destroied[2001] = { 0, };
unsigned char sim_destroied[2001] = { 0, };
unsigned char bomb[2001] = { 0, };

int main()
{
    unsigned int N, M;
    cin >> N >> M;

    unsigned int idx = 0;
    
    unsigned int Citya, Cityb;
    while (idx < M) {
        cin >> Citya >> Cityb;
        map[Citya][Cityb] = map[Cityb][Citya] = 1;
        idx++;
    }

    unsigned int K;
    cin >> K;
    idx = 0;
    unsigned int City;
    while (idx < K) {
        cin >> City;
        destroied[City] = 1;
        idx++;
    }
    
    bool find = true;
    vector<int> bombCity;

    for (unsigned int i = 1; i <= N; i++) {
        if (destroied[i] != 1) continue;
        else {
            unsigned int cnt = 0;
            unsigned int connected = 0;
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == 0) continue;
                else {
                    connected++;
                    if (destroied[j] == 1) {
                        cnt++;
                    }
                }
            }
            if (cnt == connected) {
                bomb[i] = 1;
                bombCity.push_back(i);
            }
            if ((connected !=0) && (cnt == 0)) {
                find = false;
                break;
            }
        }
    }


    if (find) {

        for (unsigned int i = 1; i <= N; i++) {
            if (bomb[i] != 1) continue;
            else {
                sim_destroied[i] = 1;
                for (int j = 1; j <= N; j++) {
                    if (map[i][j] == 0) continue;
                    else sim_destroied[j] = 1;
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (destroied[i] != sim_destroied[i]) {
                find = false;
                break;
            }
        }
    
    }

    if (find) {
        cout << bombCity.size() << endl;
        for (int i = 0; i < bombCity.size(); i++) cout << bombCity[i] << " ";
    }
    else {
        cout << -1 << endl;
    }   
    return 0;
}
*/

//Problem E
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    unsigned int N, M;
    cin >> N >> M;
    unsigned int S, E;
    cin >> S >> E;

    vector<vector<unsigned char>> map(N+1, vector<unsigned char>());
    vector<unsigned int> dist(N+1, 300000);
    for (int i = 1; i <= N; i++) {
        if (i == 1) map[i].push_back(i+1);
        else if (i == N) map[i].push_back(i - 1);
        else {
            map[i].push_back(i - 1);
            map[i].push_back(i + 1);
        }
    }

    unsigned int idx = 0;

    idx = 0;
    unsigned int first, second;
    while (idx < M) {
        cin >> first >> second;
        map[first].push_back(second);
        map[second].push_back(first);
        idx++;
    }

    vector<unsigned char> visit(N+1, 0);
    dist[S] = 0;
     
    int cur = S;
    int visitcnt = 0;
    while (visitcnt<N) {
        visit[cur] = 1;
        visitcnt++;
        //cout << cur << endl;

        for (auto iter = map[cur].begin(); iter != map[cur].end(); iter++){
            if ((visit[*iter] == 0) && (dist[*iter] > dist[cur] + 1)) {
                dist[*iter] = dist[cur] + 1;
            }
        }

        int mindist = 300001;
        for (int i = 1; i <= N; i++) {
            if ((visit[i] == 0) && dist[i] < mindist) {
                mindist = dist[i];
                cur = i;
            }
        }

    }
    //for (int i = 0; i < dist.size(); i++) cout << dist[i] << endl;

    cout << dist[E] <<endl;
   
    return 0;
}
