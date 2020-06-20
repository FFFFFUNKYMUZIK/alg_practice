#include <string>
#include <vector>

using namespace std;

long long solution(int N) {

    vector<long long> side(N, 0);
    side[0]=side[1] = 1;
    for (int i=2;i<N;i++){
        side[i]=side[i-1]+side[i-2];
    }

    vector<long long> peri(N, 0);
    peri[0] = 4;
    for (int i=1;i<N;i++){
        peri[i] = peri[i-1]+2*side[i];
    }

    return peri[N-1];
}