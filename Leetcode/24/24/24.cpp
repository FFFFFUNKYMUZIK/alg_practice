#include <iostream>


struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        if (second) head = second;

        ListNode* nfirst = NULL;
        ListNode* nsecond = NULL;

        while (first && second) {
            nfirst = second->next;
            
            if (nfirst) nsecond = nfirst->next;
            else nsecond = NULL;
            
            if (!nsecond) {
                first->next = nfirst;
            }
            else {
                first->next = nsecond;
            }
            second->next = first;

            first = nfirst;
            second = nsecond;
        }

        return head;

    }
};

int main()
{
    Solution sol;



    return 0;
}
