//Pr. 1

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& lhs, vector<int>& rhs){
    if (lhs[0]==rhs[0]) return lhs[1]<rhs[1];
     return lhs[0]<rhs[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    for (int i=0;i<routes.size();i++){
        printf("%d %d\n", routes[i][0], routes[i][1]);
    }
    
    int len = routes.size();
    int cur_end = routes[0][0]-1;
    for (int i=0;i<len;i++){
        cur_end = min(cur_end, routes[i][1]);
        if (routes[i][0]<=cur_end) continue;
        cur_end = routes[i][1];
        answer++;
    }
    
    return answer;
}

//Pr. 2

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n, long long total, vector<int>& times){
    long long possible = 0;
    for (int i=0;i<times.size();i++){
        possible += total/times[i];
    }
    return possible>=n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    int maxval = 0;
    int len = times.size();
    for (int i=0;i<len;i++){
        maxval = max(maxval, times[i]);
    }
    
    long long s = 1;
    long long e = (n/len + 1)*(long long)maxval;
    
    while(s<=e){
        long long mid = (s+e)/2;
        
        if (check(n, mid, times)){
            answer = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    
    return answer;
}