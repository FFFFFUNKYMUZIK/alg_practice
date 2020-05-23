#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        vector<ListNode*> buc;
        ListNode* cur = head;
        while (cur) {
            buc.push_back(cur);
            cur = cur->next;
        }

        int i = 0;
        int j = buc.size() - 1;

        while (i<j) {
            buc[i++]->next = buc[j];
            buc[j--]->next = buc[i];
        }
        buc[i]->next = NULL;
    }
};


int main()
{
    return 0;
}
