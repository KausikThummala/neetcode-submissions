bool isFreqsame(int freq1[],int freq2[]){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //todo permutation in string
        int freq[26]={0};
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']+=1;
        }
        //now we have to create a window of size s1
        int  wind_idx=0;
        int idx=0;
        int wind_size=s1.size();
        for(int i=0;i<s2.size();i++){
            wind_idx=0;
            idx=i;
            int wind_freq[26]={0};
            while(wind_idx<wind_size && idx<s2.size()){
                wind_freq[s2[idx]-'a']+=1;
                idx+=1;
                wind_idx+=1;
            }
            if(isFreqsame(freq,wind_freq)){
                return true;
            }

        }
        return false;
        
    }
};
