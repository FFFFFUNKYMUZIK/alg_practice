/*
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int n =words.size();
        
        int idx1=-1, idx2=-1;
        int mindist = n;
        
        for (int i=0;i<n;i++){
            if (words[i]==word1){
                idx1 = i;
                if (idx2!=-1){
                    mindist= min(mindist, idx1-idx2);
                }
            }
            else if (words[i]==word2){
                idx2 = i;
                if (idx1!=-1){
                    mindist= min(mindist, idx2-idx1);
                }
            }
        }
        
        return mindist;
    }
};