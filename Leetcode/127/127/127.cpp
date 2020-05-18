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

#if 0
// O(NL), 136ms

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ret = 0;
        unordered_map<string, vector<int>> hash;

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
                        for (auto it = hash[tmp].begin(); it != hash[tmp].end(); it++) {
                            if (*it != cur) {
                                tmp_q.push(*it);
                            }
                        }
                        hash[tmp].clear();
                    }
                }

            }
            cnt++;
            q.swap(tmp_q);
        }

        return ret;
    }
};

#elif 1
// O(NL), bidirection
// 80ms
#include <unordered_set>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ret = 0;
        unordered_map<string, vector<int>> hash;

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

        unordered_set<int> q1, q2;
        unordered_set<int>* ptar,* psec;
        q1.insert(n - 1);
        q2.insert(ei);

        //O(NL)
        while (!q1.empty() && !q2.empty()) {

            unordered_set<int> tmpq;
            
            if (q1.size() < q2.size()) {
                ptar = &q1;
                psec = &q2;
            }
            else {
                ptar = &q2;
                psec = &q1;
            }
        
            
            for (auto it = ptar->begin(); it != ptar->end(); it++) {
                if (psec->find(*it) != psec->end()) {
                    return cnt;
                }

                for (int j = 0; j < L; j++) {

                    string tmp = wordList[*it];
                    tmp[j] = '-';
                    if (hash.find(tmp) != hash.end()) {
                        for (auto it2 = hash[tmp].begin(); it2 != hash[tmp].end(); it2++) {
                            if (*it2 != *it) {
                                tmpq.insert(*it2);
                            }
                        }
                        hash[tmp].clear();
                    }
                }
            }
            ptar->swap(tmpq);
            cnt++;
        }

        return ret;
    }
};

#else

//reference solution, 36ms
//O(NL)
#include <unordered_set>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS usando las dos puntas
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, * phead, * ptail;
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail->find(word) != ptail->end()) {
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return 0;
    }
};

#endif

int main()
{
    Solution sol;

    int ret;
    vector<string> in = vector<string>({ string("f"), string("b") });
    ret = sol.ladderLength(string("a"), string("b"),in);

    return 0;

}
