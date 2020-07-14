/*
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt = 0;
            
        vector<int> hash(26, 0);
        
        int n = s.length();
        int m = t.length();
        if (n!=m) return false;
        for (int i=0;i<n;i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        
        for (int i=0;i<26;i++){
            if (hash[i]!=0) return false;
        }
        return true;
    }
};