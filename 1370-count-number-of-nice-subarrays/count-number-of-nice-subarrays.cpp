class Solution {
public:
    int sol(vector<int>& nums, int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        int count=0;
        int odd=0;
        while(r<nums.size()){
           if(nums[r]%2) odd++;

           while(odd>k){
            if(nums[l]%2) odd--;
            l++; 
           }
           count+=(r-l+1);  
           r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
     return sol(nums,k)-sol(nums,k-1);   
    }
};