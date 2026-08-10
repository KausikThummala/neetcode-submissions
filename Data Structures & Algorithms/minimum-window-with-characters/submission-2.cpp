class Solution {
public:
    string minWindow(string s, string t) {
        //here for the minimum window string just check the validity of the window
        int formed_count=0;
        //just take the size to be 128
        int required_count=0;
        vector<int> tFreq(128,0);
        vector<int> windowF(128,0);
        //now map the index to its freq
        for(auto c:  t){
            if(tFreq[c]==0) required_count++;
            //only keep track of the unique characters
            tFreq[c]++;
        }
        //now check use left and right for dec and inc the window based on certain conditions
        int left=0;
        int min_length=INT_MAX;
        int start_idx=0;
        for(int right=0;right<s.size();right++){
            char rightChar=s[right];
            windowF[rightChar]++;
            if(tFreq[rightChar]>0 && windowF[rightChar]==tFreq[rightChar] ){
                formed_count++;
            }
            //if formed ==required then
            while(formed_count==required_count){
                int length=right-left+1;
                if(length<min_length){
                    min_length=length;
                    start_idx=left;
                }
                char left_char=s[left];
                windowF[left_char]--;
                left++;
                if(tFreq[left_char]>0 && windowF[left_char]<tFreq[left_char]){
                    formed_count--;
                }
                //if after shrinking the window ,the window is not valid then dec formed_count
            }
        }
        if(min_length==INT_MAX) return "";
        else return s.substr(start_idx,min_length);
        
    }
};
