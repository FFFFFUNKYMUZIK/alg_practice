#include <iostream>
#include <algorithm>

#define INF 98765432

using namespace std;

int N;


int solve(int A, int B, int term, int step) {

	if (A == B) return 0;
	if (A > B || term == 0) return INF;
	

	int ret = INF;

	if (term % 2 == 0) {
		if ((A - step <= 0) && (B + step > N)) {
			return INF;
		}

		if (A - step > 0) {
			ret = solve(A - step, B - step, term / 2, 2*step);
		}
		
		if (B + step <= N){
			ret = min( ret, solve(A + step, B + step, term / 2, 2*step));
		}
	}
	else {
		ret = solve(A + step, B - step, term / 2, 2*step);
	}

	if (ret == INF) {
		return INF;
	}

	return ret + 1;
}


int main()
{
	int A, B;
	cin >> N >> A >> B;

	int tmp = A;
	A = min(A, B);
	B = max(tmp, B);

	int term = B - A;

	if (term % 2) {
		printf("-1\n");
		return 0;
	}

	term /= 2;
	int step = 1;

	int ret = solve(A, B, term, step);

	if (ret == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ret);
	}
}