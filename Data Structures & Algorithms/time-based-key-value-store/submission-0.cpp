class TimeMap {
public:
unordered_map <string,vector<pair<int,string>>> mpp;
//map a string to a vector of pairs
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});

        
    }
    
    string get(string key, int timestamp) {
        string ans="";
        if(!mpp.count(key)){
            return "";
        }
        vector<pair<int,string>> & pairs =mpp[key];
        int l=0;
        int r=pairs.size()-1;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(pairs[mid].first <=timestamp){
                //try for a larger timestamp
                ans=pairs[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }

        }
        return ans;
        
    }
};
