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
The tree may not be perfect binary tree.(differ from problem 116)
*/

class Solution {
public:

    //return earliest child node from root level nodes
    Node* next_node(Node* root) {
        root = root->next;
        while (root) {
            if (root->left) return root->left;
            if (root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }

    Node* connect(Node* root) {
        if (!root) return root;

        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            }
            else {
                root->left->next = next_node(root);
            }
        }
        
        if (root->right) {
            root->right->next = next_node(root);
        }

        connect(root->right);
        connect(root->left);

        return root;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
