#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#if 0

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = s.length();
        int m = words.size();

        if (n == 0 || m == 0) return vector<int>();

        int wordlen = words[0].length();

        if (wordlen == 0) {
            vector<int> ret;
            for (int i = 0; i <= m; i++) {
                ret.push_back(i);
            }
            return ret;
        }

        if (n < m * wordlen) return vector<int>();

        unordered_map<string, vector<int>> pi;
        unordered_map<string, vector<int>> wordidx;

        for (int i = 0; i < m; i++) {
            string word = words[i];
            wordidx[word].push_back(i);
            if (pi.find(word) != pi.end()) {
                continue;
            }
            int acc = 0;
            vector<int>& cpi = pi[word];
            cpi.resize(wordlen);
            for (int j = 1; j < wordlen; j++) {
                while (acc > 0 && word[j] != word[acc]) {
                    acc = cpi[acc - 1];
                }
                if (word[j] == word[acc]) {
                    cpi[j] = ++acc;
                }
            }
        }

        vector<vector<int>> wordsubidx(n);
        unordered_map<string, int> done;

        for (int i = 0; i < m; i++) {
            string word = words[i];
            if (done[word] != 0) {
                continue;
            }
            vector<int>& cpi = pi[word];
            int acc = 0;
            for (int j = 0; j < n; j++) {
                while (acc > 0 && s[j] != word[acc]) {
                    acc = cpi[acc - 1];
                }
                if (s[j] == word[acc]) {
                     ++acc;
                }
                if (acc == wordlen) {
                    wordsubidx[j - (wordlen - 1)].insert(wordsubidx[j-(wordlen-1)].end(), wordidx[word].begin(), wordidx[word].end());
                    acc = cpi[acc - 1];
                }
            }
            done[word] = 1;
        }

        vector<int> ret;
        

        for (int i = 0; i < n; i++) {
            vector<int> visit(m, 0);
            int cnt = 0;
            int start = i;

            while (start <= n - wordlen) {
                vector<int>& wcidx = wordsubidx[start];
                bool find = false;
                for (int j = 0; j < wcidx.size(); j++) {
                    if (visit[wcidx[j]] == 0) {
                        visit[wcidx[j]] = 1;
                        find = true;
                        cnt++;
                        break;
                    }
                }
                if (!find || cnt==m) break;
                start += wordlen;
            }
            if (cnt == m) ret.push_back(i);
        }

        return ret;

    }
};

#elif 0
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        
        int len = s.length(); int size = words.size();
        vector<int> result;
        if (size <= 0 || len <= 0)
            return result;

        int wordsize = words[0].length();
        if (size * wordsize > len)
            return result;
        unordered_map<string, int>word;
        for (int i = 0; i < size; i++)
        {
            word[words[i]]++;
        }

        for (int i = 0; i < len - (wordsize * size) + 1; i++)
        {
            unordered_map<string, int>visit;
            int j = 0;
            for (; j < size; j++)
            {
                string w = s.substr(i + j * wordsize, wordsize);
                if (word.find(w) != word.end())
                {
                    visit[w]++;
                    if (visit[w] > word[w])
                        break;
                }
                else
                    break;
            }
            if (j == size)
                result.push_back(i);
        }
        return result;
    }
};

#else

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty())
            return result;

        int s_len = s.length();
        int num = words.size();
        int len = words[0].length();
        int w_len = len * num;

        if (len == 0) {
            for (int i = 0; i <= s.length(); ++i)
                result.push_back(i);
            return result;
        }

        unordered_map<string, int> counts;
        for (auto& w : words) {
            counts[w] += 1;
        }

        unordered_map<string, int> seen;
        int found_num = 0;

        for (int i = 0; i < len; ++i) {

            int j = i;
            int k = i;
            seen.clear();
            found_num = 0;

            while (j < s_len - w_len + 1 && k < s_len - len + 1) {
                auto cur_word = s.substr(k, len);
                // cout << "j:" << j << " k:" << k << " word:" << cur_word << endl;
                if (counts.count(cur_word)) {
                    // cout << "see " << cur_word << endl;
                    seen[cur_word] += 1;
                    found_num++;

                    while (seen[cur_word] > counts[cur_word]) {
                        // cout << "remove " << s.substr(j, len) << endl;
                        seen[s.substr(j, len)] -= 1;
                        j += len;
                        found_num--;
                    }

                    if (found_num == num) {
                        // cout << "found at " << j << endl;
                        result.push_back(j);
                    }

                    k += len;
                }
                else {
                    // cout << cur_word << " does not belong to map" << endl;
                    k += len;
                    j = k;
                    found_num = 0;
                    seen.clear();
                }
            }
        }

        return result;
    }
};


#endif

int main()
{
    Solution sol;

    string in;
    vector<string> words;

    vector<int> ret;

    /*
    in = string("barfoothefoobarman");
    words = vector<string>({ string("foo"), string("bar") });
    ret = sol.findSubstring(in, words);

    in = string("wordgoodgoodgoodbestword");
    words = vector<string>({ string("word"), string("good"), string("best"), string("word") });
    ret = sol.findSubstring(in, words);

    in = string("wordgoodgoodgoodbestword");
    words = vector<string>({ string("word"), string("good"), string("best"), string("good") });
    ret = sol.findSubstring(in, words);

    */
    in = string("wordgoodvoiddiffdiff");
    words = vector<string>({ string("word"), string("good"), string("best"), string("diff"), string("near") });
    ret = sol.findSubstring(in, words);

    
    in = string("");
    words = vector<string>();
    ret = sol.findSubstring(in, words);
    return 0;
}