class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //here u have to use a double queue
        deque <int> dq;
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            //remove indices which are not in the current window
            //remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }


        }
        return ans;
        
    }
};
