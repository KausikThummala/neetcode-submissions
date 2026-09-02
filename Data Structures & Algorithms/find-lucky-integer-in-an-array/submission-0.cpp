class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto num: arr){
            mpp[num]++;
        }
        int largest=INT_MIN;
        for(auto cell:mpp){
            if(cell.first==cell.second){
                if(cell.first>largest){
                    largest=cell.first;
                }
            }
        }
        return (largest==INT_MIN) ? -1: largest;
        
    }
};