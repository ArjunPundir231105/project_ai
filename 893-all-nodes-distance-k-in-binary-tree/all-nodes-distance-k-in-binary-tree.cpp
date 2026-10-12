/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void P(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &Parent){
        TreeNode* curr = root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                 Parent[curr->left] = curr;
                 q.push(curr->left);
            }
            if(curr->right){
                Parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> Parent;
        P(root,Parent);
        unordered_map<TreeNode*,int>visit;
        queue<TreeNode*>p;
        p.push(target);
        visit[target]=1;
        int x = 0;
        while(!p.empty()){
            int n = p.size();

            if(x==k) break;

            for(int i=0;i<n;i++){
                TreeNode* nw = p.front();
                p.pop();

                if(nw->left && visit.count(nw->left) == 0){
                    p.push(nw->left);
                    visit[nw->left] = 1;
                }
                if(nw->right && visit.count(nw->right) == 0){
                    p.push(nw->right);
                    visit[nw->right] = 1;
                }
                if(Parent[nw] && visit.count(Parent[nw]) == 0){
                    p.push(Parent[nw]);
                    visit[Parent[nw]] = 1;
                }
            }
            x++;
        }

       vector<int>ans;

        while(!p.empty()){
            TreeNode* j = p.front();
            p.pop();

             ans.push_back(j->val);
        }
       return ans; 
    }
};