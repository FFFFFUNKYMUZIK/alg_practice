/*

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*/


#if 0

// O(n) Construction
// O(nlogn) per every shortest calls
class WordDistance {
public:
    
    unordered_map<string, vector<int>> idxmap;
    
    WordDistance(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            idxmap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& vt1 = idxmap[word1];
        vector<int>& vt2 = idxmap[word2];

        int mindist = INT_MAX;
        for (int i=0;i<vt1.size();i++){
            int idx = vt1[i];
            auto it = std::lower_bound(vt2.begin(), vt2.end(), idx);
            if (it!=vt2.end()) mindist = min(mindist, *it-idx);
        }
        for (int i=0;i<vt2.size();i++){
            int idx = vt2[i];
            auto it = lower_bound(vt1.begin(), vt1.end(), idx);
            if (it!=vt1.end()) mindist = min(mindist, *it-idx);
        }
        return mindist;
    }
};

#else

// O(n) Construction
// O(n) per every shortest calls
class WordDistance {
public:
    
    unordered_map<string, vector<int>> idxmap;
    
    WordDistance(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            idxmap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& vt1 = idxmap[word1];
        vector<int>& vt2 = idxmap[word2];

        int mindist = INT_MAX;
        
        int i1 = 0 , i2 = 0;
        while(i1<vt1.size() && i2<vt2.size()){
            mindist = min(mindist, abs(vt1[i1]-vt2[i2]));
            
            if (vt1[i1]<vt2[i2]){
                i1++;
            }
            //these two cannot be the same
            else{
                i2++;
            }
            
        }
        return mindist;
    }
};



#endif

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */