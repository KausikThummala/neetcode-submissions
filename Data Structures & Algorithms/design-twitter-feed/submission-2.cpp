class Twitter {
public:
    int timer;
    Twitter() {
        timer=0;
    }
    //we need to make two maps
    unordered_map<int,unordered_set<int>> followmap;
    unordered_map<int,vector<pair<int,int>>> tweetmap;
    
    
    void postTweet(int userId, int tweetId) {
        timer++;
        tweetmap[userId].push_back({timer,tweetId});
        //push the tweet along with the time as well
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        //this is a max heap by default
        //we have to just get the ten most recent tweets
        //get the 10 most recent tweets from the user as well as the 
        //people the user follows
        followmap[userId].insert(userId);
        //push the users tweets first
        for(auto followee: followmap[userId]){
            for(auto &tweet: tweetmap[followee]){
                pq.push(tweet);
            }
        }
        vector <int> ans;
        while(!pq.empty() && (ans.size()<10)){
            ans.push_back(pq.top().second);
            //is the tweetId
            pq.pop();
        }
        return ans;


        
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
        
    }
};
