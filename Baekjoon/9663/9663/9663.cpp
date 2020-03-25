#include <iostream>
#include <vector>

using namespace std;

vector<bool> sum;
vector<bool> sub;
vector<bool> row_fill;

//increasing column
int nqueens(int col, int N) {
	if (col > N) {
		return 1;
	}
	
	int ret = 0;

	for (int row = 1; row <= N; row++) {
		if (!row_fill[row] &&
			!sum[row + col - 2] &&
			!sub[row - col + (N - 1)]) {

			row_fill[row] = true;
			sum[row + col - 2] = true;
			sub[row - col + (N - 1)] = true;

			ret += nqueens(col + 1, N);

			row_fill[row] = false;
			sum[row + col - 2] = false;
			sub[row - col + (N - 1)] = false;
		}
	}

	return ret;
}


int main()
{
	int N;
	cin >> N;

	sum = vector<bool>(2 * N - 1, false);
	sub = vector<bool>(2 * N - 1, false);
	row_fill = vector<bool>(N + 1, false);
	
	cout << nqueens(1, N) << endl;

	return 0;
}
