#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string A, B;

    cin >> A >> B;

    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, 0));

    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[A.length()][B.length()]);

    vector<char> st;
    int i = A.length(), j = B.length();
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            st.push_back(A[i - 1]);
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        printf("%c", *it);
    }


    return 0;
}
