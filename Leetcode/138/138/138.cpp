#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        map<Node*, int> nidx;
        vector<Node*> newv;
        Node* cur = head;
        int idx = 0;
        while (cur) {
            nidx[cur] = idx;
            newv.push_back(new Node(cur->val));
            idx++;
            cur = cur->next;
        }

        cur = head;
        idx = 0;
        int size = newv.size();
        while (cur) {
            if (idx < size - 1) newv[idx]->next = newv[idx + 1];
            if (cur->random) {
                newv[idx]->random = newv[nidx[cur->random]];
            }
            else {
                newv[idx]->random = NULL;
            }
            idx++;
            cur = cur->next;
        }

        return newv[0];
    }
};

int main()
{



    return 0;
}
