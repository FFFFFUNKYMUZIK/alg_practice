#include "stdafx.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode root(-1, head);
		ListNode* proot = &root;

		ListNode* tar = head, *tarnext=head->next;
		ListNode *pre, *cur, *end = head;

		while (tarnext) {
			tar = tarnext;
			tarnext = tar->next;
			pre = proot;
			cur = proot->next;
			while (cur->val<tar->val) {
				pre = pre->next;
				cur = cur->next;
			}
			if (cur == tar) end = tar;
			else {
				pre->next = tar;
				tar->next = cur;
				end->next = tarnext;
			}
		}
		return proot->next;
	}
};


int main()
{
    return 0;
}

