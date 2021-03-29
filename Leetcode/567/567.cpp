class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	int n1 = s1.length();
    	int n2 = s2.length();
    	if (n1>n2) return false;

    	vector<int> cnt(26, 0);
    	vector<int> cnt2(26, 0);

    	for (int i=0;i<n1;i++){
    		cnt[s1[i]-'a']++;
    		cnt2[s2[i]-'a']++;
    	}

    	auto comp = [](vector<int> &l, vector<int> &r){
    		for (int i = 0;i<l.size();i++){
    			if (l[i]!=r[i]) return false;
    		}
    		return true;
    	};

    	if (comp(cnt, cnt2)) return true;

    	for (int i=n1;i<n2;i++){
    		cnt2[s2[i-n1]-'a']--;
    		cnt2[s2[i]-'a']++;
    		if (comp(cnt, cnt2)) return true;
    	}

    	return false;        
    }
};