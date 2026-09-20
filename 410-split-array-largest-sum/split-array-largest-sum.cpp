class Solution {
public:
    bool canSplit(vector<int>&vec,int k,int mid){
        int sum=0;
        int count=1;
        bool ans=false;
        for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        if(sum>mid) {
        count++;
        sum=vec[i];
        }
        }
        return count<=k;
    }
   int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long answer = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canSplit(nums, k, mid)) {
            answer = mid;
            high = mid - 1;  // Try for a smaller max sum
        } else {
            low = mid + 1;
        }
    }
    return (int)answer;
}
};