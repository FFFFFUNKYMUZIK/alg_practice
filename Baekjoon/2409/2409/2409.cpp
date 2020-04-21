#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool backtrack(vector<int>& len, vector<int>& des, vector<int>& descnt, int idx, int s, int touse, int left) {

    //printf("%d ", idx);

    if (touse == 0) return true;
    if (touse > left) {
        return false;
    }

    bool ret = false;
    bool crap = true;

    for (int i = s; i < des.size(); i++) {
        int accum = 0;
        int cnt = 0;
        while (len[idx] >= des[i] && descnt[i] > 0) {
            crap = false;
            accum += des[i];
            cnt++;

            len[idx] -= des[i];
            descnt[i]--;
            
            if (backtrack(len, des, descnt, idx, i + 1, touse - accum, left - accum)) {
                ret = true;
                break;
            }
        }

        if (cnt > 0) {
            len[idx] += accum;
            descnt[i]+=cnt;
        }

        if (ret) break;
    }

    if (crap) {
        ret = backtrack(len, des, descnt, idx + 1, 0, touse, left - len[idx]);
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int M;
    cin >> M;
    
    vector<int> len(M, 0);

    int idx = 0;
    int sumlen = 0;
    while (idx < M) {
        cin >> len[idx];
        sumlen += len[idx];
        idx++;
    }

    //O(MlogM)
    sort(len.begin(), len.end());

    int N;
    cin >> N;

    vector<int> des(N, 0);

    idx = 0;
    while (idx < N) {
        cin >> des[idx];

        idx++;
    }

    //O(NlogN)
    sort(des.begin(), des.end());

    vector<int> dpsum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        dpsum[i + 1] = dpsum[i] + des[i];
    }


    int s = 1, e = N;
    int ret = 0;

    while (s <= e) {
        int mid = (s + e) / 2;


        if (dpsum[mid] > sumlen) {
            e = mid - 1;
        }
        else {
            vector<int> des_in;
            vector<int> des_cnt;

            int pre = -1;
            int lastidx = -1;
            for (int i = mid - 1; i >= 0; i--) {
                if (pre != des[i]) {
                    des_in.push_back(des[i]);
                    des_cnt.push_back(1);
                    pre = des[i];
                    lastidx++;
                }
                else {
                    des_cnt[lastidx]++;
                }
            }

            if (backtrack(len, des_in, des_cnt, 0, 0, dpsum[mid], sumlen)) {
                s = mid + 1;
                ret = mid;
            }
            else {
                e = mid - 1;
            }
        }
    }

    printf("%d\n", ret);

    return 0;
}


