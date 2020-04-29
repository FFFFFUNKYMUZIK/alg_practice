#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode* mpre=NULL, *pnext;
        
        ListNode root(0);
        root.next = head;
        ListNode* pre = &root;

        int cnt = 0;

        while (cnt < m) {
            if (++cnt == m) mpre = pre;
            pre = pre->next;
        }

        ListNode* cur = pre->next;
        while (cnt < n) {
            ++cnt;
            pnext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pnext;
        }

        mpre->next->next = cur;
        mpre->next = pre;

        return root.next;
    }
};


int main()
{

    return 0;
}