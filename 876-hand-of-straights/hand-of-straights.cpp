class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {

        if (hand.size() % W != 0)
            return false;

        multiset<int> minHeap(hand.begin(), hand.end());

        while (!minHeap.empty()) {

            int start = *minHeap.begin();

            minHeap.erase(minHeap.begin());

            for (int j = 1; j < W; j++) {

                auto it = minHeap.find(start + j);

                if (it == minHeap.end())
                    return false;

                minHeap.erase(it);
            }
        }

        return true;
    }
};