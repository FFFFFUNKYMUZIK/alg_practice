#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef struct Trie_t {
    using chmap = map<string, Trie_t*>;

    chmap child;
    string buf;

    Trie_t(){}
    Trie_t(string str) : buf(str){}
    ~Trie_t() {
        chmap::iterator it;
        for (it = child.begin(); it != child.end(); it++) {
            delete it->second;
        }
    }

    void insert(vector<string>& strbuf, int idx) {
        if (idx == strbuf.size()) {
            return;
        }

        chmap::iterator it = child.find(strbuf[idx]);

        if (it != child.end()) {
            it->second->insert(strbuf, idx + 1);
        }
        else {
            Trie_t* newTrie = new Trie_t(strbuf[idx]);
            newTrie->insert(strbuf, idx + 1);
            child.insert(make_pair(strbuf[idx], newTrie));
        }
    }

    void printAll(int depth) {
        for (int i = 1; i < depth; i++) {
            cout << "--";
        }
        if (buf.length() !=0 ) cout << buf << '\n';
        chmap::iterator it;
        for (it = child.begin(); it != child.end(); it++) {
            it->second->printAll(depth+1);
        }

    }
} Trie;


int main()
{
    int N;

    cin >> N;
    int idx = 0;

    int num;
    string food;

    Trie root;

    while (idx < N) {
        cin >> num;
        vector<string> strbuf(num);
        int idx2 = 0;
        while (idx2 < num) {
            cin >> food;
            strbuf[idx2] = food;
            idx2++;
        }
        root.insert(strbuf, 0);

        idx++;
    }

    root.printAll(0);


    return 0;
}
