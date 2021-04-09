class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
  		vector<int> cnt(26, 101);
  		int n =A.size();

  		for (int i=0;i<n;i++){
  			string& str = A[i];
  			vector<int> cnt_tmp(26, 0);

  			for (int j=0;j<str.length();j++){
  				cnt_tmp[str[j]-'a']++;  				
  			}

  			for (int k=0;k<cnt.size();k++){
  				cnt[k] = min(cnt[k], cnt_tmp[k]);
  			}
  		}

  		vector<string> ret;
  		for (int i=0;i<cnt.size();i++){
  			if (cnt[i]<=100){
  				for (int j=0;j<cnt[i];j++){
  					ret.push_back(string(1, 'a'+i));
  				}
  			}
  		}

  		return ret;
    }
};