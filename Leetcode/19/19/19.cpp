#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre;
        ListNode* nth;
        ListNode* pn = head;

        for (int i = 1; i < n; i++) {
            pn = pn->next;
        }
        pre = NULL;
        nth = head;

        while (pn->next != NULL) {
            pre = nth;
            nth = nth->next;
            pn = pn->next;
        }

        //remove head
        if (pre == NULL) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            pre->next = nth->next;
            delete nth;
        }

        return head;
    }
};


int main()
{

    return 0;
}

