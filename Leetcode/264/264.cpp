#include <algorithm>

class Solution {
public:

    int nthUglyNumber(int n) {
        int iter2 = 0, iter3 = 0, iter5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;
        int next = 0;

        vector<int> uglys(n, 0);
        uglys[0] = 1;

        for (int i=1;i<n;i++){
            next = min(next2, min(next3, next5));
            uglys[i] = next;

            if (next==next2) next2 = 2*(uglys[++iter2]);
            if (next==next3) next3 = 3*(uglys[++iter3]);
            if (next==next5) next5 = 5*(uglys[++iter5]);
        }
        return uglys[n-1];
    }
};