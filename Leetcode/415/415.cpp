class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int len = max(len1, len2);
        
        string ret;
        int over = 0;
        int cur = 0;
        int a, b;
        
        for (int i=0;i<len;i++){
            a = b = 0;
            if (i < len1){
                a = num1[len1 - i - 1] - '0';
            }
            
            if (i < len2){
                b = num2[len2 - i - 1] - '0';
            }

            cur = a + b + over;
            over = cur/10;
            cur = cur%10;
            ret = (char)(cur+'0') + ret;
        }   
        if (over) ret = '1' + ret;
        
        return ret;
    }
};