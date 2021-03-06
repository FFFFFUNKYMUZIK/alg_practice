#include "stdafx.h"
#include <vector>
#include <queue>

using namespace std;



class Solution {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

public:
	void solve(vector<vector<char>>& board) {
		int h = board.size();
		if (h == 0) return;
		int w = board[0].size();
		if (w == 0) return;

		queue<pair<int, int>> q;

		int i = 0, j = 0;
		for (; j < w; j++) {
			if (board[i][j] == 'O') q.push(make_pair(i, j));
		}
		for (i = 1; i<h - 1; i++) {
			if (board[i][0] == 'O') q.push(make_pair(i, 0));
			if (board[i][w-1] == 'O') q.push(make_pair(i, w-1));
		}
		for (j=0; i < h && j < w; j++) {
			if (board[i][j] == 'O') q.push(make_pair(i, j));
		}

		while (!q.empty()) {
			int curi = q.front().first, curj = q.front().second;
			board[curi][curj] = 'I';
			q.pop();

			for (int k = 0; k < 4; k++) {
				int ni, nj;
				ni = curi + dx[k];
				nj = curj + dy[k];
				if ((ni > 0) && (ni < h - 1) &&
					(nj > 0) && (nj < w - 1) &&
					board[ni][nj] == 'O')
					q.push(make_pair(ni, nj));
			}
		}

		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (board[i][j] == 'I') board[i][j] = 'O';
				else if (board[i][j] == 'O') board[i][j] = 'X';
			}
		}

	}
};

int main()
{
    return 0;
}

