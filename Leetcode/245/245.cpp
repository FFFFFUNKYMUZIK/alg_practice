class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        int n = words.size();
        unordered_map<string, vector<int>> um;
        
        for (int i=0;i<n;i++){
            um[words[i]].push_back(i);
        }
        
        int mindist = n;
        
        if (word1==word2){
            for (int i=1;i<um[word1].size();i++){
                vector<int>& tar = um[word1];
                mindist = min(mindist, tar[i]-tar[i-1]);
            }
        }
        else{
            for (int i=0;i<um[word1].size();i++){
                vector<int>& tar = um[word2];
                int idx = um[word1][i];
                auto it = lower_bound(tar.begin(), tar.end(), idx);
                if (it!= tar.end()) mindist = min(mindist, *it-idx);
            }
            for (int i=0;i<um[word2].size();i++){
                vector<int>& tar = um[word1];
                int idx = um[word2][i];
                auto it = lower_bound(tar.begin(), tar.end(), idx);
                if (it!= tar.end()) mindist = min(mindist, *it-idx);
            }   
        }
        return mindist;
    }
};