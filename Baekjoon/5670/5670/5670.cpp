#include <iostream>
#include <string>
#include <memory.h>
#define APB 26

using namespace std;

typedef struct Trie_t {

    char buf;
    Trie_t* child[APB];
    bool terminate;
    int childnum;
    int only_child_idx;

    Trie_t() : terminate(false), childnum(0), only_child_idx(-1) { memset(child, 0, sizeof(child)); }
    Trie_t(char c) : buf(c), terminate(false), childnum(0), only_child_idx(-1) { memset(child, 0, sizeof(child)); };
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
            childnum++;
            if (childnum == 1) {
                only_child_idx = idx;
            }
            else {
                only_child_idx = -1;
            }
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

    int propagate(int depth) {
            
        int sum = 0;

        if (childnum == 0) {
            return depth;
        }
        else if (childnum == 1) {
            if (terminate) {
                return depth + child[only_child_idx]->propagate(depth + 1);
            }
            else {
                if (depth == 0) depth = 1;
                return child[only_child_idx]->propagate(depth);
            }
        }
        else {
            if (terminate) sum += depth;
            for (int i = 0; i < APB; i++) {
                if (child[i] != nullptr) {
                    sum+=child[i]->propagate(depth + 1);
                }
            }
        }
        return sum;
    }

} Trie;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string N;
    while (getline(cin, N)) {

        int idx = 0;
        Trie root;

        string in;
        while (idx < stoi(N)) {
            cin >> in;
            root.insert(in.c_str());
            idx++;
        }

        int sum = root.propagate(0);

        printf("%.2lf\n", sum / (double)stoi(N));
        getline(cin, N);
    }

    return 0;
}
