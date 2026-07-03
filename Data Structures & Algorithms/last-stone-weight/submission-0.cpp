class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //here i need to use a max_heap
        priority_queue<int> pq;
        for(int stone: stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first!=second){
                pq.push(first-second);
            }
        }
        return (pq.empty() ? 0:pq.top());
        
    }
};
