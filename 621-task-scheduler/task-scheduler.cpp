class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        // Count frequency of each task
        for (char x : tasks) {
            mp[x]++;
        }

        // Max heap: {frequency, task}
        priority_queue<pair<int, char>> pq;

        for (auto [task, freq] : mp) {
            pq.push({freq, task});
        }

        int time = 0;

        while (!pq.empty()) {

            vector<pair<int, char>> temp;

            // One cycle can contain n + 1 tasks
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    auto [freq, task] = pq.top();
                    pq.pop();

                    freq--;
                    time++;

                    if (freq > 0) {
                        temp.push_back({freq, task});
                    }
                }
                else {
                    // No task available
                    if (temp.empty())
                        break;

                    time++;
                }
            }

            // Put remaining tasks back
            for (auto [freq, task] : temp) {
                pq.push({freq, task});
            }
        }

        return time;
    }
};