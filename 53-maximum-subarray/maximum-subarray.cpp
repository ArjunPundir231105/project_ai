class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=nums[0];
        if(nums.size()==1) return ans;
        for(int i=0;i<nums.size();i++){
         sum=max(nums[i],sum+nums[i]);
         ans=max(ans,sum);
        }
        return ans;
    }
};