#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define MAX_TRY 8

using namespace std;

int solution(int N, int number) {

    unordered_map<int, int> um;
    um[0] = 0;
    int rep = N;
    int repcnt = 1;

    for (int i = 1; i <= MAX_TRY; i++) {
        unordered_map<int, int> tmp;

        for (auto iti = um.begin(); iti != um.end(); iti++) {
            for (auto itj = iti; itj != um.end(); itj++) {
                int cnt = iti->second + itj->second;
                int a = iti->first;
                int b = itj->first;
                if (cnt == i) {
                    tmp[a + b] = um.find(a + b) != um.end() ? um[a + b] : cnt;
                    tmp[a * b] = um.find(a * b) != um.end() ? um[a * b] : cnt;
                    if (a != 0 && b != 0) {
                        if (a > b) {
                            tmp[a / b] = um.find(a / b) != um.end() ? um[a / b] : cnt;
                        }
                        else {
                            tmp[b / a] = um.find(b / a) != um.end() ? um[b / a] : cnt;
                        }
                    }
                    tmp[abs(a - b)] = um.find(abs(a - b)) != um.end() ? um[abs(a - b)] : cnt;
                }
            }
        }

        tmp[rep] = repcnt++;
        rep = rep * 10 + N;

        um.insert(tmp.begin(), tmp.end());

        if (um.find(number) != um.end()) return um[number];
    }

    return -1;

}

int main() {
    int ret;
    ret = solution(5, 12);

    ret = solution(5, 31168);

    return 0;
}