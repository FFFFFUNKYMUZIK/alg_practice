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

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;

		while(head){
			ret = (ret<<1) + head->val;
			head = head->next;
		}        

		return ret;
    }
};