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

    // Serialize
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string ans;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                ans += "N ";
                continue;
            }

            ans += to_string(node->val) + " ";

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;

        stringstream ss(data);

        string val;
        ss >> val;

        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            ss >> val;
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Right child
            ss >> val;
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};