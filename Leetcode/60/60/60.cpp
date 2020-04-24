#include <iostream>
#include <string>
#include <list>

using namespace std;

class Solution {
public:

    int getperm(int n) {
        if (n <= 1) return 1;
        return n * getperm(n - 1);
    }   

    string getPermutation(int n, int k) {
        
        string ret;

        list<char> nodes(n,0);
        char i = '1';
        for (auto it=nodes.begin();it!=nodes.end();it++){
            *it = i++;
        }

        int cnt;
        int perm = getperm(--n);
        while (k > 0 && n > 0) {
            cnt = 1 + (k-1)/perm;
            k = k % perm;
            perm /= n;
            auto it = nodes.begin();
            while (--cnt > 0) it++;
            ret += string(1, *it);
            nodes.erase(it);
            n--;
        }
        for (auto it = nodes.rbegin(); it != nodes.rend(); it++) {
                ret += string(1, *it);
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    string ret;

    ret = sol.getPermutation(3, 3);

    ret = sol.getPermutation(4, 9);

    ret = sol.getPermutation(2, 2);

    ret = sol.getPermutation(3, 2);

    return 0;
}
