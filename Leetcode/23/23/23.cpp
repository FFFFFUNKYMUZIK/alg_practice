#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 1

class Solution {
public:

    //O(lklog(k))
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];

        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int minhead_idx;
        int minval = INT_MAX;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
            }
        }

        if (pq.empty()) return NULL;

        int headidx = pq.top().second;
        ListNode* head = lists[headidx];
        lists[headidx] = head->next;
        pq.pop();
        if (head->next) pq.push(make_pair(head->next->val, headidx));

        int nextidx;
        ListNode* cur = head;
        while (!pq.empty()) {
            nextidx = pq.top().second;
            cur->next = lists[nextidx];

            pq.pop();

            cur = cur->next;
            lists[nextidx] = cur->next;
            if (cur->next) pq.push(make_pair(cur->next->val, nextidx));
        }

        return head;

    }
};

#else




#endif

int main()
{

    Solution sol;

#define NODEARR(x, y)  for (int i=0;i<x.size();i++){ \
                       y[i]=ListNode(x[i]);        \
                                              } 


    vector<int> vals({ 1, 4, 5, 1, 3, 4, 2, 6 });
    vector<ListNode> nodes(vals.size(), ListNode(0));

    NODEARR(vals, nodes);

    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[3].next = &nodes[4];
    nodes[4].next = &nodes[5];
    nodes[6].next = &nodes[7];

    vector<ListNode*> in({&nodes[0], &nodes[3], &nodes[6]});

    ListNode* ret;
    ret = sol.mergeKLists(in);


    ret = sol.mergeKLists(vector<LIstNode)

    return 0;
}