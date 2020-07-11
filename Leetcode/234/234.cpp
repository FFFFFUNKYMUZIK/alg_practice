/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
 Follow up:
 Could you do it in O(n) time and O(1) space?
 */

class Solution {
public:

    ListNode* reverse(ListNode* root) {

        ListNode* ptar = root, * pn;
        ListNode* pre = NULL;

        while (ptar) {
            pn = ptar->next;
            ptar->next = pre;
            pre = ptar;
            ptar = pn;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* first = head, * second = head;

        while (second && second->next) {
            first = first->next;
            second = second->next->next;
        }

        ListNode* ptail = reverse(first);

        while (ptail) {
            if (ptail->val != head->val) return false;
            head = head->next;
            ptail = ptail->next;
        }

        return true;
    }
};