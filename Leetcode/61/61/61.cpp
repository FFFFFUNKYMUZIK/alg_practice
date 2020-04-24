#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int n=1;
        ListNode *pn = head, *pre;
        while (pn->next) {
            n++;
            pn = pn->next;
        }
        k = k % n;
        
        if (k == 0) return head;

        pn->next = head;
        pn = head;
        while (n-- > k) {
            pre = pn;
            pn = pn->next;
        }
        head = pn;
        pre->next = NULL;

        return head;
    }
};

int main()
{
    return 0;
}

