#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
public:

    bool canPermutePalindrome(string s, unordered_map<int, int>& hash) {
        int len = s.length();
        if (len == 0) return true;

        int oddcnt = 0;

        for (int i=0;i<len;i++){
            if ((++hash[s[i]]) % 2 == 0) oddcnt--;
            else oddcnt++;
        }

        return oddcnt <= 1;
    }

    void makestring(vector<string>& out, unordered_map<int, int>& hash, int len, string& cur, string& mid){
        if (len==0){
            string rev(cur.rbegin(), cur.rend());
            out.push_back(cur + mid + rev);
            return;
        }

        char c;
        string tmp;
        for (auto it = hash.begin();it != hash.end();it++){
            if (it->second > 0){
                c = it->first;
                tmp = cur;
                cur += c;
                it->second--;
                makestring(out, hash, len-1, cur, mid);
                it->second++;
                cur = tmp;
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        int len = s.length();
        vector<string> ret = vector<string>();
        unordered_map<int, int> hash;
        
        if (len == 0 || !canPermutePalindrome(s, hash)) return ret;

        string mid;

        for (auto it = hash.begin(); it != hash.end() ; it++){
            if (it->second % 2 == 1) mid = it->first;
            it->second /= 2;        
        }

        string buf;
        makestring(ret, hash, len/2, buf, mid);

        return ret;
    }
};