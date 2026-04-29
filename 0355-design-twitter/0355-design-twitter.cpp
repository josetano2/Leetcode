class Twitter {
public:

    set<pair<int, int>> followers;
    unordered_map<int, vector<pair<int, int>>> posts;
    int now = 1;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({now, tweetId});
        now++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> followedUser;
        followedUser.push_back(userId);
        for(auto& [f, s] : followers) {
            if(f == userId) followedUser.push_back(s);
        }

        // fetch every post by every user that is followed and put it in a pq
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < followedUser.size(); i++) {
            vector<pair<int, int>>& post = posts[followedUser[i]];

            for(int j = 0; j < post.size(); j++) {
                pq.push(post[j]);
            }
        }

        vector<int> newsFeed;
        int idx = 0;
        while(idx < 10 && !pq.empty()) {
            int recent = pq.top().second;
            pq.pop();

            newsFeed.push_back(recent);
            idx++;
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followers.insert({followerId, followeeId});
    }
    
    void unfollow(int followerId, int followeeId) {
        followers.erase({followerId, followeeId});
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */