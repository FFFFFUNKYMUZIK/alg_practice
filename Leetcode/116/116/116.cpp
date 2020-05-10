#include <iostream>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
*/
class Solution {
public:

    //connect left rightmost nodes & right leftmost nodes
    void connect_sub(Node* root) {
        if (!root || !(root->left)) return;
        connect_sub(root->left);
        connect_sub(root->right);
        
        Node* l = root->left;
        Node* r = root->right;
        while (l) {
            l->next = r;
            l = l->right;
            r = r->left;
        }

    }

    Node* connect(Node* root) {
        connect_sub(root);
        return root;
    }
};

int main()
{
    return 0;
}