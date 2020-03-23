#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define SIDE 1024

typedef unsigned long long ull;

int table[SIDE + 1][SIDE + 1];

//fenwick tree

void update(vector<vector<ull>>& trees, int xidx, int yidx, int diff) {
    
    while (xidx < trees.size()) {
        int y = yidx;
        while (y < trees[xidx].size()) {
            trees[xidx][y] += diff;
            y += y & -y;
        }
        xidx += xidx & -xidx;
    }

}

ull get(vector<vector<ull>>& trees, int xidx, int yidx) {
    ull psum = 0;

    while (xidx > 0) {
        int y = yidx;
        while (y > 0) {
            psum += trees[xidx][y];
            y -= y & -y;
        }
        xidx -= xidx & -xidx;
    }

    return psum;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<ull>> fenwicks(N+1, vector<ull>(N+1, 0));
      
    int xidx = 1;
    while (xidx <= N) {
        int yidx = 1;
        int val;
        while (yidx <= N) {
            cin >> val;
            table[xidx][yidx] = val;
            update(fenwicks, xidx, yidx, val);
            yidx++;
        }
        xidx++;
    }

    int idx = 0;
    int w, x, y, c;
    int x1, y1, x2, y2;

    while (idx < M) {
        cin >> w;
        if (w == 0) {
            cin >> x >> y >> c;
            int& val = table[x][y];
            update(fenwicks, x, y, c-val);
            val = c;
        }
        else if (w == 1) {
            cin >> x1 >> y1 >> x2 >> y2;
            ull sum = 0;
            int tmp;
            if (x2 < x1) {
                tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            if (y2 < y1) {
                tmp = y2;
                y2 = y1;
                y1 = tmp;
            }
                        
            sum = get(fenwicks, x2, y2) - get(fenwicks, x2, y1-1) - get(fenwicks, x1-1, y2) + get(fenwicks, x1-1, y1-1);
            
            printf("%lld\n", sum);
        }
        idx++;
    }



    return 0;
}