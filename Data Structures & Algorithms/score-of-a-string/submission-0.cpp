class Solution {
public:
    int scoreOfString(string s) {
        //how to find the score of the string here
        int score=0;
        for(int i=1;i<s.size();i++){
            score+=abs((s[i]-'a')-(s[i-1]-'a'));
        }
        return score;

        
    }
};