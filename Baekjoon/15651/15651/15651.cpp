
#include <iostream>
#include <vector>

using namespace std;

int N;

void print_arr(int M, vector<int>& vec) {
    if (M == 0) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        vec.push_back(i + 1);
        print_arr(M - 1, vec);
        vec.pop_back();
    }
}

int main()
{
    int M;
    cin >> N >> M;

    vector<int> tmp;
    print_arr(M, tmp);

    return 0;
}

/*

#include <cstdio>
#include <memory.h>
using namespace std;

int N, M;
bool bVisted[8];
char szBuffer[20];

void dfs(register int _depth)
{
    if (_depth == M)
    {
        puts(szBuffer);
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        szBuffer[_depth * 2] = i + '1';
        dfs(_depth + 1);
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    memset(szBuffer, ' ', 2 * M);
    dfs(0);
    return 0;

}
*/