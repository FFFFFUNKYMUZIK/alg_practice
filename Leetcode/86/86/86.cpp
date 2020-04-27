#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode *cur = head;

        ListNode hs(0), hg(0);
        ListNode *ps = &hs, *pg = &hg;

        while (cur) {
            if (cur->val < x) {
                ps->next = cur;
                ps = cur;
            }
            else {
                pg->next = cur;
                pg = cur;
            }
            cur = cur->next;
        }
        ps->next = hg.next;
        pg->next = NULL;
        
        return hs.next;
    }
};

int main()
{
    return 0;
}
