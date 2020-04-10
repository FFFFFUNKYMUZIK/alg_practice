#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k <= 1 || !head) return head;

        ListNode* node = head;
        int cnt = 0;
        while (node) {
            node = node->next;
            cnt++;
        }
        
        int n_group = cnt / k;

        ListNode* root = new ListNode(0);
        ListNode* preend = root;

        ListNode* first = head;
        ListNode* nfirst = head;

        ListNode* pre;
        ListNode* cur;
        while (n_group-- > 0) {
            
            for (int i = 0; i < k; i++) {
                cur = nfirst;
                nfirst = nfirst->next;
                if (i > 0) cur->next = pre;
                else first = cur;
                pre = cur;
            }

            preend->next = cur;
            preend = first;
        }

        preend->next = nfirst;


        ListNode* ret = root->next;
        delete root;
        return ret;
    }
};

int main()
{
    return 0;
}
