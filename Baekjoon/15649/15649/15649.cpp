#include <iostream>
#include <vector>

using namespace std;

int selected[8];

int N;

void print_arr(int M, vector<int>& vec) {
    if (M == 0) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (selected[i] == 0) {
            selected[i] = 1;
            vec.push_back(i+1);
            print_arr(M - 1, vec);
            selected[i] = 0;
            vec.pop_back();
        }
    }
}

int main()
{
    int M;
    cin >> N >> M;

    vector<int> tmp;
    print_arr(M, tmp);

    return 0;
}
