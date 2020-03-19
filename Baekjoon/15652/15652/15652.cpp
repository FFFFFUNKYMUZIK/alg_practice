
#include <iostream>
#include <vector>

using namespace std;

int N;

void print_arr(int M, int start, vector<int>& vec) {
    if (M == 0) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < N; i++) {
        vec.push_back(i + 1);
        print_arr(M - 1, i, vec);
        vec.pop_back();
    }
}

int main()
{
    int M;
    cin >> N >> M;

    vector<int> tmp;
    print_arr(M, 0, tmp);

    return 0;
}
