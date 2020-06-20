#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int h = triangle.size();
    
    vector<int> dp(h+1, 0);
    for (int i=0;i<h;i++){
        for (int j=i;j>=0;j--){
         dp[j+1] = max(dp[j+1], dp[j]) + triangle[i][j];
        }
    }
    
    int maxsum = 0;
    for (int i=1;i<=h;i++){
        if (dp[i]>maxsum) maxsum=dp[i];
    }
    return maxsum;
}