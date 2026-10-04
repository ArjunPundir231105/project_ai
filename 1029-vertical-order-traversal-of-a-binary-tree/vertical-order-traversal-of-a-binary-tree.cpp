class Solution {
public:
    map<int, vector<pair<int,int>>> mp;

    void dfs(TreeNode* root, int row, int col) {
        if(!root) return;

        mp[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        dfs(root, 0, 0);

        for(auto &it : mp) {
            vector<int> temp;

            // Sort by row, then by value
            sort(it.second.begin(), it.second.end());

            for(auto &p : it.second) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};