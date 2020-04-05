#include <iostream>
#include <algorithm>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) return NULL;
        if (headA == headB) return headA;

        int lenA = 1, lenB = 1;
        ListNode* hA = headA, * hB = headB;
        while (hA->next != NULL) {
            hA = hA->next;
            lenA++;
        }
        while (hB->next != NULL) {
            hB = hB->next;
            lenB++;
        }

        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        while (lenA > 0 && lenB>0) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
            lenA--; lenB--;
        }

        return NULL;

    }
};

int main() {

    Solution sol;


    return 0;
}