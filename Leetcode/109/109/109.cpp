#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//using vector(too big memory (22.73% memory usage))
#if 0

class Solution {
public:

    TreeNode* Maketree(vector<int>& nodes, int s, int e) {
        if (e < s) return NULL;
        int mid = (s + e) / 2;
        TreeNode* cn= new TreeNode(nodes[mid]);
        cn->left = Maketree(nodes, s, mid - 1);
        cn->right = Maketree(nodes, mid + 1, e);
        return cn;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        ListNode* cn = head;
        while (cn) {
            nodes.push_back(cn->val);
            cn = cn->next;
        }
        return Maketree(nodes, 0, nodes.size()-1);
    }
};

#else

 //use slow/fast point of linked list to figure out middle element 
 //refer to : https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list
 class Solution {
 public:
     
     TreeNode* sortedListToBST(ListNode* head) {
         if (!head) return NULL;
         if (!head->next) return new TreeNode(head->val);
         
         ListNode *fp = head, *sp = head, *lp = head;

         while (fp && fp->next) {
             fp = fp->next->next;
             lp = sp;
             sp = sp->next;
         }

         TreeNode* cn = new TreeNode(sp->val);
         
         lp->next = NULL;
         cn->left = sortedListToBST(head);
         cn->right = sortedListToBST(sp->next);
         //just for restore input list
         lp->next = sp;
         
         return cn;
     }
 };
 
#endif

int main()
{
    std::cout << "Hello World!\n";
}
