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
    TreeNode* solve(int st,int end,vector<int>& postorder,int &preInd,unordered_map<int,int>&mp){
         if (st > end) return nullptr;
        int root = postorder[preInd--];
        TreeNode* nw = new TreeNode(root);
        int div = mp[root];

        nw->right = solve(div+1,end,postorder,preInd,mp);
        nw->left = solve(st,div-1,postorder,preInd,mp);
        
        return nw;
    }
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        int n = inorder.size();
        int preInd = n-1;
        return solve(0,n-1,postorder,preInd,mp);
    }
};