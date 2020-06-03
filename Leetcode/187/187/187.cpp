#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#if 0

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.length();
        vector<string> ret;
        if (n < 11) return ret;

        unordered_map<string, int> um;

        for (int i = 0; i <= n - 10;i++) {
            string cur = s.substr(i, 10);
            if (um.find(cur) == um.end()) {
                um[cur] = 1;
            }
            else {
                if (um[cur] == 1) {
                    ret.push_back(cur);
                    um[cur] = 2;
                }
            }
        }

        return ret;
    }
};

#else
#include <bitset>

//reference solution
//using bitset
//2^20 bit = 2^17 byte = 128KB
//encode 4 alphabets into 2 bit (00:A, 01:C, 10:G, 11:T)
//ex) AGTCT = 00/10/11/01/11

class Solution {
public:
    // kinda sliding window

    // there are 4 alphabets, so represeneting each with a binary number we only need 2 bits places
    // so after setting the bits, we will left shift the bits by 2.
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) {
            return res;
        }

        bitset<1 << 20> set1;
        bitset<1 << 20> set2;

        int val = 0;
        // iterating over first 10 elements
        for (int i = 0; i < 10; i++) {
            val = (val << 2) | change(s[i]);
        }
        set1.set(val);

        // as the only bits we care about is till 20 so we have to reset the higher digits to zero
        int mask = (1 << 20) - 1;
        for (int i = 10; i < s.size(); i++) {
            // left shift + remove higher bits + add the current bit
            val = ((val << 2) & mask) | change(s[i]);
            if (set2[val]) {
                continue;
            }

            if (set1[val]) {
                res.push_back(s.substr(i - 10 + 1, 10));
                set2.set(val);
            }
            else {
                set1.set(val);
            }
        }
        return res;
    }

    int change(char c) {
        switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        }
        return 0;
    }
};
#endif


int main()
{
    Solution sol;
    vector<string> ret;

    ret = sol.findRepeatedDnaSequences(string("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));

    ret = sol.findRepeatedDnaSequences(string("AAAAAAAAAAAAA"));

    return 0;
}
