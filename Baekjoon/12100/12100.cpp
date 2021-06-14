#include <iostream>
#include <vector>

using namespace std;

using board_type = vector<vector<int>>;

int op(board_type& board, int dir) {

	/* dir
	   1
	 0   2
	   3
	*/
	int N = board.size();
	int maxval = 0;

	if (dir % 2) {
		for (int j = 0; j < N; j++) {
			int idx;
			if (dir / 2) {
				idx = N - 1;
				for (int i = N - 1; i >= 0; i--) {
					maxval = max(maxval, board[i][j]);
					if (board[i][j] != 0 && idx != i) {
						if (board[i][j] == board[idx][j]) {
							board[i][j] = 0;
							board[idx][j] *= 2;
							maxval = max(maxval, board[idx][j]);
							idx--;
						}
						else if (board[idx][j] == 0) {
							board[idx][j] = board[i][j];
							maxval = max(maxval, board[i][j]);
							board[i][j] = 0;
						}
						else {
							idx--;
							board[idx][j] = board[i][j];
							maxval = max(maxval, board[i][j]);
							if (idx != i) board[i][j] = 0;
						}
					}
				}
			}
			else {
				idx = 0;
				for (int i = 0; i < N; i++) {
					maxval = max(maxval, board[i][j]);
					if (board[i][j] != 0 && idx != i) {
						if (board[i][j] == board[idx][j]) {
							board[i][j] = 0;
							board[idx][j] *= 2;
							maxval = max(maxval, board[idx][j]);
							idx++;
						}
						else if (board[idx][j] == 0) {
							board[idx][j] = board[i][j];
							maxval = max(maxval, board[i][j]);
							board[i][j] = 0;
						}
						else {
							idx++;
							board[idx][j] = board[i][j];
							maxval = max(maxval, board[i][j]);
							if (idx != i) board[i][j] = 0;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			int idx;
			if (dir / 2) {
				idx = N - 1;
				for (int j = N - 1; j >= 0; j--) {
					maxval = max(maxval, board[i][j]);
					if (board[i][j] != 0 && idx != j) {
						if (board[i][j] == board[i][idx]) {
							board[i][j] = 0;
							board[i][idx] *= 2;
							maxval = max(maxval, board[i][idx]);
							idx--;
						}
						else if (board[i][idx] == 0) {
							board[i][idx] = board[i][j];
							maxval = max(maxval, board[i][j]);
							board[i][j] = 0;
						}
						else {
							idx--;
							board[i][idx] = board[i][j];
							maxval = max(maxval, board[i][j]);
							if (idx != j) board[i][j] = 0;
						}
					}
				}
			}
			else {
				idx = 0;
				for (int j = 0; j < N; j++) {
					maxval = max(maxval, board[i][j]);
					if (board[i][j] != 0 && idx != j) {
						if (board[i][j] == board[i][idx]) {
							board[i][j] = 0;
							board[i][idx] *= 2;
							maxval = max(maxval, board[i][idx]);
							idx++;
						}
						else if (board[i][idx] == 0) {
							board[i][idx] = board[i][j];
							maxval = max(maxval, board[i][j]);
							board[i][j] = 0;
						}else {
							idx++;
							board[i][idx] = board[i][j];
							maxval = max(maxval, board[i][j]);
							if (idx != j) board[i][j] = 0;
						}
					}
					
				}
			}
		}
	}

	return maxval;
}

int backtrack(board_type& board, int trial) {

	if (trial == 0) return 0;

	int maxval = 0;

	board_type bkup = board;
	for (int i = 0; i < 4; i++) {
		board = bkup;
		maxval = max(maxval, op(board, i));
		maxval = max(maxval, backtrack(board, trial - 1));
	}

	return maxval;
}

int main() {

	int N;
	cin >> N;

	board_type board(N, vector<int>(N, 0));

	/* board input */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	/* 5 trial : 4^5 = 2^10 = 1024 */
	int ret = backtrack(board, 5);

	cout << ret;

	return 0;
}