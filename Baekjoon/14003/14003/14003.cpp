#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);
    vector<int> len(N + 1, 0);

    int idx = 1;
    while (idx <= N) {
        cin >> arr[idx];
        idx++;
    }

    int maxidx = 1;
    int maxlen = 1;

    for (int i = 1; i <= N; i++) {
        int maxval = 0;
        for (int j = 1; j < i; j++) {
            if (maxval < len[j] && arr[j] < arr[i]) maxval = len[j];
        }
        len[i] = maxval + 1;
        if (len[i] > maxlen) {
            maxlen = len[i];
            maxidx = i;
        }
    }

    printf("%d\n", maxlen);

    int i = maxidx;
    vector<int> st;
    while (i > 0) {
        st.push_back(arr[i]);
        if (i == 1) break;

        int j = i - 1;
        while (j > 0) {
            if ((len[j] == len[i] - 1) && (arr[j] < arr[i])) {
                break;
            }
            j--;
        }
        i = j;
    }

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        printf("%d ", *it);
    }

    return 0;
}
