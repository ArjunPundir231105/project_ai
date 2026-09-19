class Solution {
public:
    bool canShipInDays(vector<int>& weights, int capacity, int days) {
        int dayCount = 1, currentLoad = 0;
        
        for (int i=0;i<weights.size();i++) {
            currentLoad=currentLoad+weights[i];
            if (currentLoad > capacity) {
                dayCount++;
                currentLoad = weights[i];
            }
        }
        return dayCount<=days; 
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShipInDays(weights, mid, days)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
