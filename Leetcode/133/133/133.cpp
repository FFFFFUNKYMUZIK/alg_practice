#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    vector<Node*> buc;

    Node* cloneGraph_sub(Node* node) {

        Node* nn = new Node(node->val);
        buc[node->val] = nn;

        for (int i = 0; i < node->neighbors.size(); i++) {
            if (buc[node->neighbors[i]->val]) nn->neighbors.push_back(buc[node->neighbors[i]->val]);
            else {
                nn->neighbors.push_back(cloneGraph_sub(node->neighbors[i]));
            }
        }
        return nn;

    }

    Node* cloneGraph(Node* node) {
        if (!node) return node;

        buc = vector<Node*>(101, NULL);
        return cloneGraph_sub(node);
    }
};

int main()
{
    Solution sol;



    return 0;
}
