class MedianFinder {
    priority_queue<long> small, large;

public:
    MedianFinder() {
        
    }

    void addNum(int num) {

        // Add to small first
        small.push(num);

        // Move largest from small to large
        // as a negative number
        large.push(-small.top());
        small.pop();

        // Keep small same size or one bigger
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {

        // Odd number of elements
        if (small.size() > large.size()) {
            return small.top();
        }

        // Even number of elements
        return (small.top() - large.top()) / 2.0;
    }
};