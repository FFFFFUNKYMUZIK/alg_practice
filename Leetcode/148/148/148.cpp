#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

	typedef struct part_t {
		ListNode* s,* e;
		int dist;
	} part;

public:

	part merge(part l, part r) {

		ListNode* ln = l.s;
		ListNode* rn = r.s;

		ListNode root(-1);
		ListNode* cur = &root;
		
		while (ln && rn) {
			if (ln->val < rn->val) {
				cur->next = ln;
				ln = ln->next;
			}
			else {
				cur->next = rn;
				rn = rn->next;
			}
			cur = cur->next;
		}

		while (ln) {
			cur->next = ln;
			ln = ln->next;
			cur = cur->next;
		}
		while (rn) {
			cur->next = rn;
			rn = rn->next;
			cur = cur->next;
		}

		return { root.next, cur, l.dist+r.dist + 1 };
	}

	part mergesort(part in) {
		if (in.dist == 0) return in;
		
		ListNode* l,* m,* r;
		l = in.s;
		r = in.e;
		m = in.s;

		
		int i = 0;
		while (i < in.dist / 2) {
			i++;
			m = m->next;
		}
		ListNode* rl = m->next;

		part lh = mergesort(part{l, m, i});
		part rh = mergesort(part{rl, r, in.dist - i - 1});

		lh.e->next = NULL;
		rh.e->next = NULL;
		return merge(lh, rh);
	}

	ListNode * sortList(ListNode* head) {
		if (!head) return head;
		ListNode* tail = head;
		int dist = 0;
		while (tail->next) {
			tail = tail->next;
			dist++;
		}
		part in{head, tail, dist};
		part ret = mergesort(in);
		return ret.s;
	}
};

int main()
{
	Solution sol;

	ListNode in[4] = { {1} ,{2}, {3}, {4} };
	in[0].next = &in[2];
	in[1].next = &in[0];
	in[2].next = NULL;
	in[3].next = &in[1];

	ListNode* ret;
	ret = sol.sortList(&in[3]);

    return 0;
}

