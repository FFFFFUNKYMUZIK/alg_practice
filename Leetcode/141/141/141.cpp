#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Follow up:

Can you solve it using O(1) (i.e. constant) memory?
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;

        ListNode* fn = head->next, * sn = head->next->next;

        while (sn) {
            if (fn == sn) return true;

            fn = fn->next;
            sn = sn->next;
            if (!sn) break;
            sn = sn->next;
        }

        return false;
    }
};

using namespace std;

int main()
{
    return 0;
}