#include <iostream>

using namespace std;

int p[100001];

int find_(int x) {
    
    if (p[x] == x) {
        return x;
    }
    else {
        p[x] = find_(p[x]);
        return p[x];
    }
}

bool union_(int x) {
    int px = find_(x);
    
    if (px == 0) {
        return false;
    }
    else {
        p[px] = px - 1;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int G, P;
    cin >> G>>P;
    int idx = 0;

    for (int i = 1; i <= G; i++) {
        p[i] = i;
    }

    int gi;
    bool satisfy = true;
    int maxidx;
    while (idx < P) {
        cin >> gi;
        if (!union_(gi)) {
            maxidx = idx;
            idx++;
            break;
        }
        idx++;
    }

    while (idx < P) {
        cin >> gi;
        idx++;
    }
    
    cout << maxidx << '\n';

    return 0;
}
