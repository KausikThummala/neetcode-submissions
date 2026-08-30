class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //we need to fill the gaps after placing the most frequent element
        //in position
        int max_count=0;
        int max_freq=0;
        //a vector
        vector<int> count(26,0);
        for(auto task: tasks){
            count[task-'A']++;
        }
        for(int i=0;i<26;i++){
            if(max_freq<count[i]){
                max_freq=count[i];
            }
        }
        for(int i=0;i<26;i++){
            if(count[i]==max_freq){
                max_count++;
            }
        }
        int result=(max_freq-1)*(n+1)+max_count;
        return max(result,(int)tasks.size());
    }
};
