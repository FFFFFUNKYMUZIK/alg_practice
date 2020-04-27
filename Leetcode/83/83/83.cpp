#include <iostream>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode root(0);
        ListNode* pre = &root;
        ListNode* cur = head;

        while (cur) {
            while (cur->next != NULL && cur->val == cur->next->val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }

        return root.next;
    }
};

int main()
{
    return 0;
}
