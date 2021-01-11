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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    	int l1h = 0, l2h = 0;

    	ListNode* c = l1;
    	while(c){
    		c = c->next;
    		l1h++;
    	}

    	c = l2;
    	while(c){
    		c = c->next;
    		l2h++;
    	}

    	int n = max(l1h,l2h);
    	vector<int> nodes(n + 1, 0);

    	for (int i=0;i<n + 1;i++){
    		if (n + 1 - i<=l1h){
    			nodes[i] += l1->val;
    			l1 = l1->next;
    		}
    		if (n + 1 - i<=l2h){
    			nodes[i] += l2->val;
    			l2 = l2->next;
    		}
    	}
    	for (int i=n;i>=0;i--){
			if (nodes[i] >= 10){
				nodes[i-1] += 1;
				nodes[i] -= 10;
			}    		
    	}

    	ListNode* head = new ListNode();
    	ListNode* pre, *cur;
    	head->val = nodes[0];
    	pre = head;
    	for (int i=1;i<n + 1;i++){
    		cur = new ListNode(nodes[i], NULL);
    		pre->next = cur;
    		pre = cur;
    	}

    	if (head->val == 0){
    		cur = head->next;
    		delete head;
    		head = cur;
    	}

        return head;
    }
};