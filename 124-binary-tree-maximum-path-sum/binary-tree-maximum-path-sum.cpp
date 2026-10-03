class Solution {
public:
    int ans = INT_MIN;

    int maxPath(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));

        // Path passing through current node
        ans = max(ans, root->val + left + right);

        // Return only one side to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }
};