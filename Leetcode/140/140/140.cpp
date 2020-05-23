#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:

    map<string, vector<string>> sm;
    vector<string> ret;
    int len;
    vector<int> dp;
    
    bool partof(string& s, string& p) {
        int slen = s.length();
        int plen = p.length();
        if (s < p) return false;
        for (int i = 0; i < plen; i++) {
            if (s[i] != p[i]) return false;
        }

        return true;
    }

    bool traverse(int st, string& s, string& bucket) {
        if (st == len) {
            ret.push_back(bucket.substr(1));
            return true;
        }
        int& retdp = dp[st];
        if (retdp == 0) return retdp;
        retdp = 0;
        
        string key = s.substr(st, 1);
        string tar = s.substr(st);

        for (int i = 0; i < sm[key].size(); i++) {
            if (partof(tar, sm[key][i])) {
                string tmp = bucket;
                bucket += " " + sm[key][i];
                retdp |= traverse(st + sm[key][i].length(), s, bucket);
                bucket = tmp;
            }
        }
        return retdp;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, vector<string>>().swap(sm);
        vector<string>().swap(ret);
        len = s.length();
        dp = vector<int>(len, -1);

        for (int i = 0; i < wordDict.size(); i++) {
            sm[wordDict[i].substr(0, 1)].push_back(wordDict[i]);
        }
        string bucket;
        traverse(0, s, bucket);

        return ret;
    }
};

int main()
{
    Solution sol;

    string s("catsanddog");
    vector<string> dict({ string("cat"), string("cats"), string("and"), string("sand"), string("dog") });

    vector<string> ret;

    ret = sol.wordBreak(s, dict);

    return 0;
}
