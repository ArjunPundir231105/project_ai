class Solution {
public:
    bool check(int a,int m,int k,vector<int>& bloomDay){
    int x=0;
    for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=a){
                x++;
             if (x == k) {
                    m--;
                    x = 0;
                }
            }
            else x=0;
        }
    return m<=0;    
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = high;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,m,k,bloomDay)){
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        } 
    return result;    
    }
};