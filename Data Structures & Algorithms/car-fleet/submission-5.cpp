class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //for the car fleet maintain a stack and maintain a vector of pairs
        vector <pair<int,double>> cars;
        for(int i=0;i<position.size();i++){
            double time =(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        //sort it based on position
        sort(cars.begin(),cars.end());
        //a new fleet will be formed only if time > st.top
        stack <double> st;
        for(int i=cars.size()-1;i>=0;i--){
            double time=cars[i].second;
            if(st.empty() || (time>st.top())){
                st.push(time);
            }
            //in the other case it will just join the fleet
        }
        return st.size();
        
    }
};
