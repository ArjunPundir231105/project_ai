class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0;
        int right=0;
        for(int i=0;i<k;i++) left+=cardPoints[i];
        int idx = cardPoints.size()-1;
        int ans=left;
        for(int i=k-1;i>=0;i--){
            left-=cardPoints[i];
            right+=cardPoints[idx];
            idx--;
            ans=max(ans,left+right);
        }
      return ans;  
    }
};