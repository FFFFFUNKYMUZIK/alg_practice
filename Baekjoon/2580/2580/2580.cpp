#include <iostream>
#include <vector>

using namespace std;

#define BLOCK_IDX(i,j) ((i-1)/3*3 + (j+2)/3)

vector<vector<int>> table(10, vector<int>(10, 0));
vector<pair<int, int>> zeroes;

vector<vector<bool>> row_candidate(10, vector<bool>(10,false));
vector<vector<bool>> col_candidate(10, vector<bool>(10, false));
vector<vector<bool>> block_candidate(10, vector<bool>(10, false));

bool fill_sudoku(int zidx) {

    if (zidx >= zeroes.size()) return true;
    
    int tx = zeroes[zidx].first;
    int ty = zeroes[zidx].second;

    int ret = false;

    for (int i = 1; i < 10;i++) {
        if (!row_candidate[tx][i] &&
            !col_candidate[ty][i] &&
            !block_candidate[BLOCK_IDX(tx, ty)][i])
        {
            table[tx][ty] = i;

            row_candidate[tx][i] = true;
            col_candidate[ty][i] = true;
            block_candidate[BLOCK_IDX(tx, ty)][i] = true;

            if (fill_sudoku(zidx + 1)) {
                ret = true;
                break;
            }

            row_candidate[tx][i] = false;
            col_candidate[ty][i] = false;
            block_candidate[BLOCK_IDX(tx, ty)][i] = false;

            table[tx][ty] = 0;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N = 9;

    int val;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> val;
            table[i][j] = val;
            row_candidate[i][val] = true;
            col_candidate[j][val] = true;
            block_candidate[ BLOCK_IDX(i,j)][val] = true;
            if (val == 0) {
                zeroes.push_back(make_pair(i,j));
            }
        }
    }

    fill_sudoku(0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}

