#include <string>

using namespace std;

/*
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#define CAP 26

class Trie {

bool terminate;
Trie* np[CAP];

public:
    /** Initialize your data structure here. */
    Trie() {
	terminate = false;
	for (int i=0;i<CAP;i++){
		np[i]=nullptr;
	}        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
	if (word.empty()){
		terminate = true;
        return;
	}        
	
	int npidx = word[0]-'a';

    if (np[npidx] == nullptr){
        np[npidx] = new Trie();
    }
   
	np[npidx]->insert(word.substr(1));
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
	if (word.empty()){
		return terminate;
	}

	int npidx = word[0]-'a';        
	if (np[npidx] != nullptr){
		return np[npidx]->search(word.substr(1));
	}
	return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
	if (prefix.empty()){
		return true;
	}

	int npidx = prefix[0]-'a';        
	if (np[npidx] != nullptr){
		return np[npidx]->startsWith(prefix.substr(1));
	}
	return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main(){

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

return 0;
}