class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low = 0;
        int high = n1;

        while(low<=high){
            int val = (low+high)/2;
            int val2 = (n1+n2+1)/2 - val;
            
            double left1,left2,right1,right2;

            if(val==0) left1=INT_MIN;
            else left1= nums1[val-1];

            if(val==n1) right1 = INT_MAX;
            else right1 = nums1[val];

            if(val2==0) left2=INT_MIN;
            else left2= nums2[val2-1];

            if(val2==n2) right2 = INT_MAX;
            else right2 = nums2[val2];

            if(left1<=right2 && left2<=right1){
                if((n1 + n2) % 2 == 1) return max(left1, left2);
                return (min(right1, right2) + max(left1, left2)) / 2.0;
             }
            else if( left1 > right2) high = val - 1;
            else low = val + 1; 
            }
     return -1; 
        }
};