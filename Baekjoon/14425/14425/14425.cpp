#include <iostream>

/*
#include <string>
#include <set>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int idx = 0;
    
    set<string> strset;

    string in;
    while (idx < N) {
        cin >> in;
        strset.insert(in);
        idx++;
    }

    idx = 0;
    int cnt = 0;
    set<string>::iterator itend = strset.end();

    //binary search
    while (idx < M) {
        cin >> in;
        if (strset.find(in) != itend) cnt++;
        idx++;
    }

    cout << cnt << endl;

    return 0;
}
*/


//using Trie
#include <string>
#include <map>
#include <memory.h>
#define APB 26

using namespace std;

typedef struct Trie_t {

    char buf;
    Trie_t* child[APB];
    bool terminate;

    Trie_t() : terminate(false) { memset(child, 0, sizeof(child)); }
    Trie_t(char c) : buf(c), terminate(false) { memset(child, 0, sizeof(child)); };
    ~Trie_t() {
        for (int i = 0; i < APB; i++) {
            if (child[i] != nullptr) {
                delete child[i];
            }
        }
    }

    void insert(const char* pstr) {
        if (*pstr == '\0') {
            terminate = true;
            return;
        }

        int idx = *pstr - 'a';
        if (child[idx] == nullptr) {
            child[idx] = new Trie_t(*pstr);
        }

        child[idx]->insert(pstr + 1);
    }

    bool find(const char* pstr) {
        if (*pstr == '\0') {
            if (terminate) {
                return true;
            }
            else {
                return false;
            }
        }

        int idx = *pstr - 'a';
        if (child[idx] == nullptr) {
            return false;
        }

        return child[idx]->find(pstr + 1);
    }

} Trie;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    int idx = 0;

    Trie root;

    string in;
    while (idx < N) {
        cin >> in;
        root.insert(in.c_str());
        idx++;
    }

    idx = 0;
    int cnt = 0;

    while (idx < M) {
        cin >> in;
        if (root.find(in.c_str())) { cnt++; }
        idx++;
    }

    cout << cnt << '\n';

    return 0;
}
