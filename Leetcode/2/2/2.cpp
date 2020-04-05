#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int exceed = 0;
        int sum;

        ListNode* pRoot = new ListNode(0);
        ListNode* p = pRoot;
        
        while (l1 != NULL || l2 != NULL) {
            sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += exceed;
            exceed = sum / 10;
            sum = sum % 10;
            
            p->next = new ListNode(sum);
            p = p->next;

        }

        if (exceed != 0) {
            p->next = new ListNode(exceed);
        }
        
        p = pRoot->next;
        delete pRoot;

        return p;
    }
};

int main()
{

    Solution sol;



    return 0;
}