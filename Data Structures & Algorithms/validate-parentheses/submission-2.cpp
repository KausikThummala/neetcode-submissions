class Solution {
public:
    bool isValid(string s) {
        //map the closed to the open parentheses here
        unordered_map<char,char> mpp;
        mpp[')']='(';
        mpp[']']='[';
        mpp['}']='{';
        stack<char> st;
        for(auto c: s){
            if(mpp.contains(c)){
                if(!st.empty() && st.top()==mpp[c]) st.pop();
                else return false;
            }
            else st.push(c);
        }
        return (st.size()==0);
        //push all the openning parentheses and see if you can pop those 
        //parentheses if u can else return false
    }
};
