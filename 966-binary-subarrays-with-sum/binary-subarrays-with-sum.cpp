class Solution {
public:
    int sol(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        long long sum=0;
        long long count=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
      return count;  
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sol(nums,goal)-sol(nums,goal-1);
    }
};