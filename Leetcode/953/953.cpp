#define ALPHABET 26

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

    	bool ret = true;
        vector<int> ordervec(ALPHABET, 0);

        for (int i=0;i<ALPHABET;i++){
        	ordervec[order[i] - 'a'] = i;
        }

        int alen, blen;
        for (int i=0;i<words.size() - 1;i++){
        	const auto& a = words[i];
        	const auto& b = words[i+1];

        	alen = a.length();
        	blen = b.length();
        	int j = 0;
        	while(j<alen && j<blen &&
        			a[j] == b[j])
        		j++;
        	
        	if ((j==blen && j<alen) ||
        		(j<alen && (ordervec[a[j]-'a'] > ordervec[b[j]-'a']))) return false;
        }

        return ret;
    }
};