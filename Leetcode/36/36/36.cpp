#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int width = 9;

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowfill(width, vector<int>(width, 0)), columnfill(width, vector<int>(width, 0));
        vector<vector<vector<int>>> blockfill(width/3, vector<vector<int>>(width/3, vector<int>(width, 0)));

        for (int i = 0; i < board.size(); i++) {
            vector<char>& row = board[i];
            for (int j = 0; j < row.size(); j++) {
                char& cur = board[i][j];
                int cidx = cur - '1';
                if (cur == '.') continue;
                else {
                    if ((rowfill[i][cidx] != 1) &&
                        (columnfill[j][cidx] != 1) &&
                        blockfill[i / 3][j / 3][cidx] != 1) {
                        rowfill[i][cidx] = 1;
                        columnfill[j][cidx] = 1;
                        blockfill[i / 3][j / 3][cidx] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    bool ret;

    vector<vector<char>> board;

    board = vector<vector<char>>({
            vector<char>({'5', '3', '.', '.', '7', '.', '.', '.', '.'}),
            vector<char>({'6', '.', '.', '1', '9', '5', '.', '.', '.'}),
            vector<char>({'.', '9', '8', '.', '.', '.', '.', '6', '.'}),
            vector<char>({'8', '.', '.', '.', '6', '.', '.', '.', '3'}),
            vector<char>({'4', '.', '.', '8', '.', '3', '.', '.', '1'}),
            vector<char>({'7', '.', '.', '.', '2', '.', '.', '.', '6'}),
            vector<char>({'.', '6', '.', '.', '.', '.', '2', '8', '.'}),
            vector<char>({'.', '.', '.', '4', '1', '9', '.', '.', '5'}),
            vector<char>({'.', '.', '.', '.', '8', '.', '.', '7', '9'})
        });

    ret = sol.isValidSudoku(board);


    board = vector<vector<char>>({
            vector<char>({'8', '3', '.', '.', '7', '.', '.', '.', '.'}),
            vector<char>({'6', '.', '.', '1', '9', '5', '.', '.', '.'}),
            vector<char>({'.', '9', '8', '.', '.', '.', '.', '6', '.'}),
            vector<char>({'8', '.', '.', '.', '6', '.', '.', '.', '3'}),
            vector<char>({'4', '.', '.', '8', '.', '3', '.', '.', '1'}),
            vector<char>({'7', '.', '.', '.', '2', '.', '.', '.', '6'}),
            vector<char>({'.', '6', '.', '.', '.', '.', '2', '8', '.'}),
            vector<char>({'.', '.', '.', '4', '1', '9', '.', '.', '5'}),
            vector<char>({'.', '.', '.', '.', '8', '.', '.', '7', '9'})
        });

    ret = sol.isValidSudoku(board);

    return 0;
}