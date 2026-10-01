class Twitter {
public:

    // follower -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> result;

        // max heap
        // {timestamp, tweetId, userId, index}
        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // User's own tweets
        if (!tweets[userId].empty()) {

            int index = tweets[userId].size() - 1;

            auto [timestamp, tweetId] = tweets[userId][index];

            pq.push({timestamp, tweetId, userId, index});
        }

        // Followed users
        for (int followee : following[userId]) {

            if (!tweets[followee].empty()) {

                int index = tweets[followee].size() - 1;

                auto [timestamp, tweetId] =
                    tweets[followee][index];

                pq.push({
                    timestamp,
                    tweetId,
                    followee,
                    index
                });
            }
        }

        // Get 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {

            auto [timestamp, tweetId, user, index] = pq.top();

            pq.pop();

            result.push_back(tweetId);

            // Move to previous tweet of same user
            index--;

            if (index >= 0) {

                auto [prevTime, prevTweet] =
                    tweets[user][index];

                pq.push({
                    prevTime,
                    prevTweet,
                    user,
                    index
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};