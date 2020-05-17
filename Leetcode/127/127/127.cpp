#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;


/*
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ret = 0;
        unordered_map<string, list<int>> hash;

        int n = wordList.size();
        if (n == 0) return ret;
        int L = wordList[0].size();
        
        
        wordList.push_back(beginWord);
        n++;

        //O(NL)
        int ei = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) ei = i;
            for (int j = 0; j < L; j++) {
                string tmp = wordList[i];
                tmp[j] = '-';
                hash[tmp].push_back(i);
            }
        }

        if (ei == -1) return ret;

        int cnt = 1;

        queue<int> q;
        q.push(n - 1);

        //O(NL)
        while (1) {

            queue<int> tmp_q;
            if (q.empty()) break;
 
            while (!q.empty()) {
                
                int cur = q.front();
                q.pop();

                if (cur == ei) {
                    return cnt;
                }

                for (int j = 0; j < L; j++) {
                    string tmp = wordList[cur];
                    tmp[j] = '-';
                    if (hash.find(tmp) != hash.end()) {
                        for (auto it = hash[tmp].begin(); it != hash[tmp].end(); ) {
                            if (*it != cur) {
                                tmp_q.push(*it);
                            }
                            it = hash[tmp].erase(it);
                        }
                    }
                }

            }
            cnt++;
            q.swap(tmp_q);
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    int ret;
    vector<string> in = vector<string>({ string("f"), string("b") });
    ret = sol.ladderLength(string("a"), string("b"),in);

    return 0;

}
