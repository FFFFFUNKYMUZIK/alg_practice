/*

Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?

*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int i=0,j=s.size()-1;
        
        //reverse original sentense
        while(i<j){
            char tmp = s[i];
            s[i]=s[j];
            s[j]=tmp;
            i++;j--;
        }
        
        int word = 0;        
        
        int l = 0;
        s.push_back(' ');
        
        for (int i=0;i<s.size();i++){
            if (s[i]==' '){
                int r = i-1;
                while(l<r){
                    char tmp = s[r];
                    s[r]=s[l];
                    s[l]=tmp;
                    l++;r--;
                }
                l=i+1;
            }
        }
        s.pop_back();
    }
};