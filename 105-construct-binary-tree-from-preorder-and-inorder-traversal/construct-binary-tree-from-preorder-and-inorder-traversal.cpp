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
    TreeNode* solve(int st,int end,vector<int>& preorder,int &preInd,unordered_map<int,int>&mp){

         if (st > end) return nullptr;
        int root = preorder[preInd++];
        TreeNode* nw = new TreeNode(root);
        int div = mp[root];

        nw->left = solve(st,div-1,preorder,preInd,mp);
        nw->right = solve(div+1,end,preorder,preInd,mp);

        return nw;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        int n = inorder.size();
        int preInd = 0;
        return solve(0,n-1,preorder,preInd,mp);
    }
};