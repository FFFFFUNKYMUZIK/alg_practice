#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    //ltbr
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };

    bool find(vector<vector<char>>& board, const char* word, int y, int x) {
        if (*word == 0) return true;
        if (y>=board.size() || y<0 ||
            x>=board[0].size() || x<0 ||
            board[y][x]==0 ||
            word[0] != board[y][x]) return false;

        char tmp = board[y][x];

        board[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            if (find(board, word+1, y+dy[i], x+dx[i])) return true;
        }
        board[y][x] = tmp;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]  && find(board, word.c_str(), i, j)) return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> board;
    bool ret;

    board = vector<vector<char>>({ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} });
    ret = sol.exist(board, string("ABCCED"));

    ret = sol.exist(board, string("SEE"));

    ret = sol.exist(board, string("ABCB"));

    return 0;
}