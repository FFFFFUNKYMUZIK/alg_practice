#include <iostream>
#include <vector>

using namespace std;
#define SDK_WIDTH 9

class Solution {
public:

    vector<vector<int>> rowbin;
    vector<vector<int>> colbin;
    vector<vector<int>> blkbin;
    vector<pair<int, int>> zerobin;

#define BLKIDX(r,c) ((r)/3 * 3 + (c)/3)

    bool fillSudoku(int zidx, vector<vector<char>>& board) {
        if (zidx == zerobin.size()) return true;
        
        int row = zerobin[zidx].first, col = zerobin[zidx].second;

        vector<int> cand;
        for (int i = 0; i < SDK_WIDTH; i++) {
            if (rowbin[row][i] == 0 &&
                colbin[col][i] == 0 &&
                blkbin[BLKIDX(row, col)][i] == 0) {

                rowbin[row][i] = 1;
                colbin[col][i] = 1;
                blkbin[BLKIDX(row, col)][i] = 1;
                board[row][col] = '1' + i;

                if (fillSudoku(zidx + 1, board)) {
                    return true;
                }
                board[row][col] = '.';
                rowbin[row][i] = 0;
                colbin[col][i] = 0;
                blkbin[BLKIDX(row, col)][i] = 0;

            }
        }

        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rowbin = vector<vector<int>>(SDK_WIDTH, vector<int>(SDK_WIDTH, 0));
        colbin = vector<vector<int>>(SDK_WIDTH, vector<int>(SDK_WIDTH, 0));
        blkbin = vector<vector<int>>(SDK_WIDTH, vector<int>(SDK_WIDTH, 0));
        vector<pair<int, int>>().swap(zerobin);



        char cur;
        for (int row = 0; row < SDK_WIDTH; row++) {
            for (int col = 0; col < SDK_WIDTH; col++) {
                if ((cur = board[row][col]) == '.') {
                    zerobin.push_back(make_pair(row, col));
                }
                else {
                    rowbin[row][cur - '1'] = 1;
                    colbin[col][cur - '1'] = 1;
                    blkbin[BLKIDX(row, col)][cur - '1'] = 1;
                }
            }
        }

        fillSudoku(0, board);

        return;
    }
};

int main()
{
    Solution sol;
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

    sol.solveSudoku(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }


    return 0;
}
