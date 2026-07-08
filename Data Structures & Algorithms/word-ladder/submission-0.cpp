class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //you have to apply BFS here so count the number of BFS traversals
        unordered_set <string> words(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int count=1;
        //for every BFS traversal increment the count
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return count;
                }
                //try all the 26 placements for the word at each particular index
                for(int k=0;k<word.size();k++){
                    char org=word[k];
                    for(char ch='a';ch<='z';ch++){
                        word[k]=ch;
                        if(words.contains(word)){
                            q.push(word);
                            //remove that word after processing it
                            words.erase(word);

                        }
                    }
                    word[k]=org;
                }
            }
            count++;
        }
        return 0;
        
    }
};
