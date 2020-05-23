#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/

class Solution {
public:


    vector<int> dp;
    map<string, vector<string>> sm;
    int len;

    bool partof(string& s, string& p){
        int slen = s.length();
        int plen = p.length();
        if (s < p) return false;
        for (int i = 0; i < plen; i++) {
            if (s[i] != p[i]) return false;
        }

        return true;
    }

    bool traverse(int st, string& s) {
        if (st == len) return true;
        int& ret = dp[st];
        if (ret != -1) return ret;
        
        string key = s.substr(st, 1);

        string tar = s.substr(st);
        for (int i = 0; i < sm[key].size(); i++) {
            if (partof(tar, sm[key][i])) {
                if (traverse(st + sm[key][i].length(), s)) return (ret = true);
            }
        }

        return (ret = false);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, vector<string>>().swap(sm);
        len = s.length();
        dp = vector<int>(len, -1);
        for (int i = 0; i < wordDict.size(); i++) {
            sm[wordDict[i].substr(0,1)].push_back(wordDict[i]);
        }
        return traverse(0, s);
    }
};

int main()
{
    Solution sol;

    bool ret;

    string in1;
    vector<string> in2;

    in1 = string("leetcode");
    in2 = vector<string>({string("leet"), string("code")});
    ret = sol.wordBreak(in1, in2);

    in1 = string("applepenapple");
    in2 = vector<string>({ string("apple"), string("pen") });
    ret = sol.wordBreak(in1, in2);

    in1 = string("catsandog");
    in2 = vector<string>({ string("cats"), string("dog"), string("sand"), string("and"), string("cat") });
    ret = sol.wordBreak(in1, in2);

    return 0;
}