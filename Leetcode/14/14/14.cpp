#include <iostream>
#include <vector>
#define ALPHABET 26

using namespace std;

#if 0

//using modified Trie
class Solution {
public:

    typedef struct Trie_t {
        bool terminal;
        int next_idx;
        char buf;
        Trie_t* next[ALPHABET];

        Trie_t() : buf(-1), terminal(false), next_idx(-1) { memset(next, 0, sizeof(next)); }
        Trie_t(char c) : buf(c), terminal(false), next_idx(-1) { memset(next, 0, sizeof(next)); }
        ~Trie_t() {
            for (int i = 0; i < ALPHABET; i++) {
                if (next[i] != nullptr) {
                    delete next[i];
                }
            }
        }

        int insert(const char* pstr, int len) {
            if (*pstr == '\0') {
                terminal = true;
                return len;
            }
            if (terminal == true) return len;

            int idx = *pstr - 'a';
            if (next[idx] == nullptr && next_idx == -1) {
                next[idx] = new Trie_t(*pstr);
                next_idx = idx;
            }
            else if (next[idx] == nullptr) {
                terminal = true;
                return len;
            }

            return next[idx]->insert(pstr + 1, len + 1);
        }

        string get(void) {
            string ret;

            if (buf != -1) {
                ret.push_back(buf);
            }

            if (terminal) return ret;
            else {
                return ret + next[next_idx]->get();
            }
        }

    } Trie;

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        Trie root;
        int prefix_len = 0;
        for (int i = 0; i < strs.size(); i++) {
            if ((prefix_len = root.insert(strs[i].c_str(), 0)) == 0 ) break;
        }
        return root.get();
    }
};

#else


class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        
        string ret = strs[0];
        int checklen = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            int j;
            for (j = 0; j < checklen && j < strs[i].length(); j++) {
                if (ret[j] != strs[i][j]) {
                    break;
                }
            }
            ret = ret.substr(0, j);
            if ((checklen = j) == 0) break;
        }


        return ret;
    }
};




#endif

int main()
{
    Solution sol;

    string ret;

    vector<string> in;

    in = vector<string>({string("flower"), string("flow"), string("flight"), });
    ret = sol.longestCommonPrefix(in);
    in = vector<string>({ string("dog"), string("racecar"), string("car"), });
    ret = sol.longestCommonPrefix(in);
    in = vector<string>();
    ret = sol.longestCommonPrefix(in);

    return 0;

}