class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        int mid=0;
        while(l<=r){
            mid=l+((r-l)/2);
            long long hours=0;
            for(int x: piles){
                hours +=((x+mid-1)/mid);
            }
            if(hours<=h){
                ans=mid;
                r=mid-1;
                //try a smaller value if it satifies the condition
            }
            else{
                l=mid+1;
            }

        }
        return ans;
        
    }
};
