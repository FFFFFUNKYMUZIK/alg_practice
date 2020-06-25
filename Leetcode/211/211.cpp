class WordDictionary {
public:
    
    WordDictionary * pnxt[26];
    bool terminal;
        
    /** Initialize your data structure here. */
    WordDictionary() {
        memset(pnxt, 0, sizeof(pnxt));
        terminal = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.empty()){
            terminal = true;
            return;
        }
        
        int idx = word[0] - 'a';
        if (!pnxt[idx]){
            pnxt[idx] = new WordDictionary();
        }
        pnxt[idx]->addWord(word.substr(1));    
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (word.empty()){
            return terminal;    
        }
        
        if (word[0] == '.'){
            for (int i=0;i<26;i++){
                if (pnxt[i] && pnxt[i]->search(word.substr(1))) return true;
            }
        }
        else{
            int idx = word[0] - 'a';
            if (pnxt[idx]){
                return pnxt[idx]->search(word.substr(1));
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */