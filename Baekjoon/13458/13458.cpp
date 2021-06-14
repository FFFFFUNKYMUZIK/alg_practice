#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, B, C;

	cin >> N;

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) cin >> A[i];
		
	cin >> B >> C;
	using ll = long long;
	ll ans = 0;
	ll remain;
#define DIVUP(m,n) (((m)+(n)-1)/(n))
	for (int i = 0; i < N; i++) {
		remain = max(0, A[i] - B);
		ans += (DIVUP(remain, C) + 1);
	}

	cout << ans;

	return 0;
}