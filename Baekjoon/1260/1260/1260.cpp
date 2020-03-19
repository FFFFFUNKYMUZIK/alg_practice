// 1260.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <queue>
#include <memory.h>

using namespace std;

char graph[1001][1001];
char visit[1001];

int main()
{
 
    int N, M;
    int start;

    cin >> N >> M >> start;

    int idx = 0;

    int va, vb;
    while (idx < M) {
        cin >> va >> vb;
        graph[va][vb] = graph[vb][va] = 1;
        idx++;
    }

    stack<int> vst;
    //DFS
    vst.push(start);
    while (!vst.empty()) {
        int cur = vst.top();
        vst.pop();
        if (visit[cur] == 0) {
            cout << cur << " ";
            visit[cur] = 1;
            
            for (int i = N; i >= 1; i--) {
                if ((graph[cur][i] != 0) && (visit[i] == 0))
                    vst.push(i);
            }
        }
    }
    cout << endl;

    memset(visit, 0, sizeof(visit));

    queue<int> vque;
    //BFS
    vque.push(start);
    while (!vque.empty()) {
        int cur = vque.front();
        vque.pop();
        if (visit[cur] == 0) {
            cout << cur << " ";
            visit[cur] = 1;

            for (int i = 1; i <= N; i++) {
                if ((graph[cur][i] != 0) && (visit[i] == 0)) {
                    vque.push(i);
                }
            }
        }

    }

    return 0;

}