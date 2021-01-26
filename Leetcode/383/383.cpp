class Solution {
	#define ALP 26
public:
    bool canConstruct(string ransomNote, string magazine) {
        
    	vector<int> occ(ALP, 0);
    	
    	for (int i=0;i<magazine.length();i++){
    		occ[magazine[i] - 'a']++;
    	}

    	for (int i=0;i<ransomNote.length();i++){
    		if (--occ[ransomNote[i] - 'a'] < 0) return false;
    	}
    	
    	return true;
    }
};