#include <iostream>
#include <vector>
#include <cmath>

#define INF 1000000.0

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<double, double>> coord(n+1, make_pair(0.0, 0.0));

    int idx = 1;
    double x, y;
    while (idx <= n) {
        cin >> x >> y;
        coord[idx] = make_pair(x, y);
        idx++;
    }


    vector<bool> visit(n+1, false);
    vector<double> weight(n+1, INF);
    
    weight[1] = 0;

    double ret = 0;

    for (int i = 0; i < n; i++) {

        int next = 0;

        for (int j = 1; j <= n; j++) {
            if (!visit[j] && (weight[j] < weight[next])) {
                next = j;
            }
        }

        if (next == 0) break;

        visit[next] = true;
        ret += weight[next];

        for (int j = 1; j <= n; j++) {
            if (j == next) continue;
            double dist = sqrt(pow((coord[j].first - coord[next].first), 2) + pow((coord[j].second - coord[next].second), 2));
            if (!visit[j] && (dist<weight[j])) {
                weight[j] = dist;
            }
        }

    }

    cout << ret << endl;

    return 0;
}
