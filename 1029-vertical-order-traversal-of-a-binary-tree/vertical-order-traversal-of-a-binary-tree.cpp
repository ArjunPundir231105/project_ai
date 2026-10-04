/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto [current,index] = q.front();
            q.pop();

            auto [x,y] = index;
            mp[y].push_back({x,current->val});

            if(current->left) q.push({current->left,{x+1,y-1}});
            if(current->right) q.push({current->right,{x+1,y+1}});
        }
        vector<vector<int>> result;
        for(auto [col,item]:mp){
         vector<int>ans;
         sort(item.begin(),item.end());
         for(auto [row,val]:item) ans.push_back(val);
         result.push_back(ans);
        }
        return result;
    }
};