#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#if 0

//iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;

        ListNode* front, * back;
        back = head->next;
        front = head;
        front->next = nullptr;

        ListNode* nextback;
        while (back) {
            nextback = back->next;
            back->next = front;
            front = back;
            back = nextback;
        }
        return front;
    }
};

#else

//recursive solution
class Solution {
public:

    using pLL = pair < ListNode*, ListNode * >;

    pLL reversePart(ListNode* head) {
        if (!head->next) return make_pair(head, head);

        pLL ret = reversePart(head->next);

        ret.second->next = head;
        ret.second = head;
        return ret;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        
        pLL ret = reversePart(head);
        ret.second->next = nullptr;

        return ret.first;
    }
};


#endif


int main()
{
    return 0;
}