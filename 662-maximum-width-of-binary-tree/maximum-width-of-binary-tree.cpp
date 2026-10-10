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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});
        long long ans=0;
        while(!q.empty()){
            int n=q.size();
            bool c= false;
            long long start=0;
            long long end=0;
            for(int i=0;i<n;i++){
                auto [node,idx]= q.front();
                q.pop();
                if(!c)start=idx;
                c=true;
                end=idx;
                long long s=idx-start;
                if(node->left) q.push({node->left,2*s});
                if(node->right) q.push({node->right,2*s+1});
            }
        ans=max(ans,end-start+1);    
        }
    return ans;    
    }
};