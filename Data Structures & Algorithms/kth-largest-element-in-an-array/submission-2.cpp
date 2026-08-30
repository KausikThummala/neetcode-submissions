class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //use a min_heap;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto num: nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
    }
};
