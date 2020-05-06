#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* Maketree(vector<int>&nums, int s, int e) {
        if (e < s) return NULL;
        int mid = (s + e) / 2;
        TreeNode* cn = new TreeNode(nums[mid]);
        cn->left = Maketree(nums, s, mid - 1);
        cn->right = Maketree(nums, mid + 1, e);
        return cn;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Maketree(nums, 0, nums.size() - 1);
    }
};

int main()
{


    return 0;
}
