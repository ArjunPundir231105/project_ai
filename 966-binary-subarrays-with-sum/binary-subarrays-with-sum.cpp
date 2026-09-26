class Solution {
public:
    int sol(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int l = 0;
        int sum = 0;
        long long count = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sol(nums, goal) - sol(nums, goal - 1);
    }
};