class Solution {
public:
bool check(vector<int>&nums,int mid,int threshold){
    int count=0;
    for(int i=0;i<nums.size();i++){
    if(nums[i]%mid==0)count=count+nums[i]/mid;
    else count=count+nums[i]/mid+1;
}
return (count <= threshold);
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums,mid,threshold)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};