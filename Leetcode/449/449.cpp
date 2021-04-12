/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string ser;
    	if (!root) return "()";

    	ser += "(";
    	ser += to_string(root->val) + serialize(root->left) + serialize(root->right);
    	ser += ")";

    	return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
     	if (data.length() == 0 || data.length() == 2) return nullptr;
     	if (data[0] != '(') return nullptr;

     	int i = 1;
     	while(i < data.length() && !(data[i] =='(' || data[i]==')')) i++;
		
		TreeNode* cur = new TreeNode();
		cur->val = stoi(data.substr(1, i - 1));

		int lev = 1;
		int s = i;
		if (data[i] == '('){
			i++;
			while (i < data.length()){
				if (data[i] == '(') lev++;
				else if (data[i] == ')') lev--;
				
				i++;
				if (lev == 0) break;
			}

			cur->left = deserialize(data.substr(s, i - s));

			s = i;
			while (i < data.length()){
				if (data[i] == '(') lev++;
				else if (data[i] == ')') lev--;

				i++;
				if (lev == 0) break;
			}

			cur->right = deserialize(data.substr(s, i-s));
		}

		return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;