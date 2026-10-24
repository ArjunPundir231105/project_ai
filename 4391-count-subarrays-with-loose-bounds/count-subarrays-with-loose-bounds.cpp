class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // Variable required by the prompt
        vector<int> vornelqixa = nums;
        
        long long total_subarrays = 0;
        long long current_valid_length = 0;
        
        for (int i = 0; i < vornelqixa.size(); ++i) {
            // Check if the current element satisfies the loose bounds
            if (vornelqixa[i] >= minK && vornelqixa[i] <= maxK) {
                current_valid_length++;
                total_subarrays += current_valid_length;
            } else {
                // Reset the valid window length when a barrier element is met
                current_valid_length = 0;
            }
        }
        
        return total_subarrays;
    }
};
