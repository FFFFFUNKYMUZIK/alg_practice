#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#if 0

//time O(NLlogL) where L is maximum length of string
//space O(NL)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        if (n == 0) return vector<vector<string>> ();

        map<string, int> idxmap;
        vector<vector<string>> ret;

        string str;
        int cnt = 0;
        for (int i = 0; i < strs.size(); i++) {
            string& ostr = strs[i];
            str = strs[i];
            sort(str.begin(), str.end());

            if (idxmap.find(str) != idxmap.end()) {
                ret[idxmap[str]].push_back(ostr);
            }
            else {
                ret.push_back(vector<string>(1, ostr));
                idxmap[str] = cnt;
                cnt++;
            }

        }
        return ret;
    }
    
};

#else


//time O(26*NL) = O(NL) where L is maximum length of string
//space O(NL)


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        if (n == 0) return vector<vector<string>>();
        
        map<vector<int>, int> idxmap;
        vector<vector<string>> ret;
                
        int cnt = 0;
        for (int i = 0; i < strs.size(); i++) {
            string& str = strs[i];
            vector<int> key(26, 0);
            for (int i = 0; i < str.length(); i++) {
                key[str[i] - 'a']++;
            }

            if (idxmap.find(key) != idxmap.end()) {
                ret[idxmap[key]].push_back(str);
            }
            else {
                ret.push_back(vector<string>(1, str));
                idxmap[key] = cnt;
                cnt++;
            }

        }
        return ret;
    }

};

#endif

int main()
{

    Solution sol;
    vector<vector<string>> ret;

    vector<string> in;

    in = vector<string>({ "eat", "tea", "tan", "ate", "nat", "bat" });
    ret = sol.groupAnagrams(in);


    return 0;
}
