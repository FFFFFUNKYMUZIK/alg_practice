#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Note: Do not modify the linked list.

Follow-up:
Can you solve it without using extra space?
*/

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return NULL;

        ListNode* fn = head->next, * sn = head->next->next;
        int cnt = 1;

        while (sn) {
            if (fn == sn) {
                //find loop
                fn = head;
                sn = head;
                for (int i = 0; i < cnt; i++) {
                    sn = sn -> next;
                }
                while (fn != sn) {
                    fn = fn->next;
                    sn = sn->next;
                }
                return fn;
            }

            fn = fn->next;
            sn = sn->next;
            if (!sn) break;
            sn = sn->next;
            cnt++;
        }

        return NULL;
    }
};

int main()
{
    return 0;
}
