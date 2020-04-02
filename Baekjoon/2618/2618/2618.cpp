#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, W;

vector<vector<int>> dp;
vector<pair<int, int>> pos;

int getdist(int event1, int event2) {
	pair<int, int>& e1pos = pos[event1];
	pair<int, int>& e2pos = pos[event2];

	return abs(e1pos.first - e2pos.first) + abs(e1pos.second - e2pos.second);
}

int solve(int event,int cop1, int cop2) {
	if (event == W + 1)
		return 0;

	int& ret = dp[cop1][cop2];
	if (ret != -1) return ret;

	int dp1 = solve(event + 1, event, cop2) + getdist(cop1, event);
	int dp2 = solve(event + 1, cop1, event) + getdist(cop2, event);

	return ret = min(dp1, dp2);
}

void trace(int event, int cop1, int cop2) {
	if (event == W + 1)
		return;

	int& ret = dp[cop1][cop2];

	int dp1 = dp[event][cop2] + getdist(cop1, event);
	int dp2 = dp[cop1][event] + getdist(cop2, event);

	if (dp1 < dp2) {
		printf("1\n");
		trace(event + 1, event, cop2);
	}
	else {
		printf("2\n");
		trace(event + 1, cop1, event);
	}
}


int main() {

	cin >> N >> W;

	dp = vector<vector<int>>(W + 2, vector<int>(W + 2, -1));
	pos = vector<pair<int, int>>(W + 2, make_pair(0, 0));
	   
	int idx = 1;
	int x, y;
	while (idx <= W) {
		cin >> x >> y;
		pos[idx] = { x, y };
		idx++;
	}
	pos[0] = { 1, 1 };
	pos[W+1] = { N, N };

	printf("%d\n", solve(1, 0, W+1));

	trace(1, 0, W + 1);

	return 0;
}