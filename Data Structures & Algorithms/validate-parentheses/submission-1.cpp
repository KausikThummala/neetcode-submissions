class Solution {
public:
    bool isValid(string s) {
        //maintain a stack
        unordered_map <char,char> mpp;
        mpp[')']='(';
        mpp['}']='{';
        mpp[']']='[';
        stack <char> st;
        for(int i=0;i<s.size();i++){
            if(mpp.count(s[i])){
                if((!st.empty()) && st.top()==mpp[s[i]]){
                    st.pop();
                }
                else return false;
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        return false;
        
    }
};
