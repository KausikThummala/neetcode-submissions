class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //here find the max_freq and also find the elements whose freq is
        //equal to the max_freq
        if(n==0) return tasks.size();
        int max_freq=INT_MIN;
        int max_count=0;
        vector<int>freq(26,0);
        for(auto c: tasks){
            freq[c-'A']++;
        }
        for(int i=0;i<26;i++){
            if(max_freq<freq[i]) max_freq=freq[i];
        }
        for(int i=0;i<26;i++){
            if(freq[i]==max_freq) max_count++;
        }
        int ans=(n+1)*(max_freq-1)+max_count;
        return max(ans,(int)tasks.size());



        
    }
};
