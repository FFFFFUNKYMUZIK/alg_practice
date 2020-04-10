#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* cur;
        ListNode* head;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        
        cur = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        while (l1) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }

        return head;
    }
};

int main()
{
    int* a, *b;
    int c = 3, d = 4;
    a = 0;
    b = &d;
    if (a && b) {
        c++;
    }

    return 0;
}
