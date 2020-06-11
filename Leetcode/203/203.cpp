
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

	ListNode root(-1, head);
	ListNode* pre = &root,*cur = head;        

	while(cur){
		if (cur->val==val){
			pre->next = cur->next;
			//free(cur);
			cur=pre->next;
		}
		else{
			pre = cur;
			cur = cur->next;
		}
	}

	return root.next;	
    }
};

int main(){

return 0;
}