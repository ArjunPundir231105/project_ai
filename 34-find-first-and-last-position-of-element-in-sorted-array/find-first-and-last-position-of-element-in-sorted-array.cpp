class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int low = 0;
     int high = nums.size()-1; 
     vector<int>result;

     while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>=target) high = mid-1;
        else low=mid+1;
     }  

     int first = high + 1;

if (first >= nums.size() || nums[first] != target)
    return {-1, -1};
     result.push_back(high+1);

     low = 0;
     high = nums.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]<=target) low = mid+1;
        else high=mid-1;
     }  
     result.push_back(low-1);

     return result;
    }
};