class TrieNode{
    public:
        TrieNode * children[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
        
    }
    
    void addWord(string word) {
        TrieNode * curr=root;
        for(char ch: word){
            int index =ch-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    bool dfs(string &word,int pos,TrieNode * node){
        //we have matched the characters from the word to the word present in the TrieNode
        if(pos==word.size()){
            return node->isEnd;
        }
        char ch=word[pos];
        if(ch=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    if(dfs(word,pos+1,node->children[i])){
                        return true;
                    }
                }
            }
            return false;

        }
        else{
            int index=ch-'a';
            if(node->children[index]==NULL) return false;
            return dfs(word,pos+1,node->children[index]);
        }
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
};
