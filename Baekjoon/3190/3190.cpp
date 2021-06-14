
#include <iostream>
#include <vector>

using namespace std;

using board_type = vector<vector<int>>;

int main() {

	int N, K, L;
	cin >> N >> K;

	board_type board(N, vector<int>(N, -1));

	/* board input */
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		board[x - 1][y - 1] = 4;
	}

	cin >> L;

	int t;
	char c;

	using op = struct { int t; char c; };
	vector<op> opv;
	for (int i = 0; i < L; i++) {
		cin >> t >> c;
		opv.push_back({ t,c });
	}

	vector<int> dx{ 1, 0, -1, 0 };
	vector<int> dy{ 0, -1, 0, 1 };

	t = 1;
	int op_idx = 0;
	int dir_idx = 0;

	x = 1;
	y = 1;
	int tail_x = 1, tail_y = 1;
	int tail_dir = -1;
	board[0][0] = 0;
	int nx, ny;
	int len = 1;

	while (1) {

		nx = x + dy[dir_idx];
		ny = y + dx[dir_idx];

		if (nx <= 0 || ny <= 0 ||
			nx > N || ny > N) break;

		if (board[nx - 1][ny - 1] >= 0) { /* obstacle! */
			if (board[nx - 1][ny - 1] < 4) { /* my body! */
				break;
			}
			len++;
		}
		else {
			tail_dir = board[tail_x - 1][tail_y - 1];
			board[tail_x - 1][tail_y - 1] = -1;
			tail_x += dy[tail_dir];
			tail_y += dx[tail_dir];
		}
		
		x = nx;
		y = ny;

		if (op_idx < L && opv[op_idx].t == t) {
			if (opv[op_idx].c == 'D') { /* right */
				dir_idx--;
				if (dir_idx < 0) dir_idx = 3;
			}
			if (opv[op_idx].c == 'L') { /* left */
				dir_idx++;
				if (dir_idx > 3) dir_idx = 0;
			}
			op_idx++;
		}
		board[x - 1][y - 1] = dir_idx;

		t++;
	}

	cout << t;

	return 0;
}