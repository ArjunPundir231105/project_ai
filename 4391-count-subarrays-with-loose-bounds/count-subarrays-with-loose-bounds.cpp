class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total_subarrays = 0;
        long long current_valid_length = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                current_valid_length++;
                total_subarrays += current_valid_length;
            }
            else current_valid_length = 0; 
        }
        
        return total_subarrays;
    }
};
