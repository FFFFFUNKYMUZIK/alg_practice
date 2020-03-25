#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321

using namespace std;

int N;
vector<vector<int>> sngy;
vector<int> teamA;
vector<int> teamB;

int pick(int valA, int valB, int idx) {

    if (idx > N) return abs(valA - valB);

    int ret = MAX;
    int A = valA;
    int B = valB;

    if (teamA.size() < N / 2) {
        for (int i = 0; i < teamA.size(); i++) {
            A += sngy[teamA[i]][idx];
        }
        teamA.push_back(idx);
        int result = pick(A, valB, idx + 1);
        teamA.pop_back();
        if (ret > result) {
            ret = result;
        }
    }

    if (teamB.size() < N / 2) {
        for (int i = 0; i < teamB.size(); i++) {
            B += sngy[teamB[i]][idx];
        }
        teamB.push_back(idx);
        int result = pick(valA, B, idx + 1);
        teamB.pop_back();
        if (ret > result) {
            ret = result;
        }
    }

    return ret;
}

int main()
{
    cin >> N;

    sngy = vector<vector<int>>(N+1, vector<int>(N+1, 0));


    teamA.reserve(N / 2);
    teamB.reserve(N / 2);

    int val;
    int idx = 1;
    while (idx <= N) {
        int idx2 = 1;
        while (idx2 <= N) {
            cin >> val;
            if (idx < idx2) {
                sngy[idx][idx2] += val;
            }
            else {
                sngy[idx2][idx] += val;
            }
            idx2++;
        }
        idx++;
    }
        
    printf("%d\n", pick(0, 0, 1));

    return 0;
}
