class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0) return false;
        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int card : hand) {
            if (freq[card] == 0) minHeap.push(card);
            freq[card]++;
        }
        while (!minHeap.empty()) {
            int start = minHeap.top();
            for (int i = 0; i < W; i++) {
                int card = start + i;
                if (freq[card] == 0) return false;
                freq[card]--;
                if (freq[card] == 0) {
                    if (card != minHeap.top()) return false;
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};