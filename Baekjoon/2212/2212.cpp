#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void){
    
    int N,K;

    cin>>N>>K;
    if (K>=N){
        cout<<0<<endl;
        return 0;
    }

    vector<int> sensors(N, 0);

    int pos;
    for (int i=0;i<N;i++){
        cin>>pos;
        sensors[i] = pos;
    }

    sort(sensors.begin(), sensors.end());
    vector<int> dist(N-1, 0);
    for (int i=1;i<N;i++){
        dist[i-1] = sensors[i]-sensors[i-1];
    }
    sort(dist.begin(), dist.end());

    long long ans = 0;
    for (int i=0;i<N-K;i++){
        ans += dist[i];
    }

    cout<<ans<<endl;

    return 0;
}
