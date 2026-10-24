class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = 0;
        int n = nums.size();
        long long count =0;
        for(int right = 0;right<n;right++){
            if(nums[right] > maxK || nums[right] < minK){
                left = right+1;
            }
            count += right-left+1;
        }
        return count;
    }
};