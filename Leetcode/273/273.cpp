class Solution {
public:
    string numberToWords(int num) {
        
        string ret;
        int phrase, cur;

        vector<string> p2 = vector<string>({"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"});
        vector<string> p1 = vector<string>({"empty", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});
        vector<string> p0 = vector<string>({"Ten", "Eleven" , "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"});
        vector<string> unit = vector<string>({"", "Thousand", "Million", "Billion", "Trillion"});
        int ucnt = 0;

        if (num == 0) return string("Zero");

        while (num > 0){
            string tmp;
            phrase = num%1000;
            cur = phrase;
            num/=1000;

            if (phrase >= 100) tmp = p2[phrase/100 - 1] + string(" Hundred");
            phrase = phrase % 100;
            if (phrase >= 20){
                if (tmp.length()>0)
                    tmp = tmp + string(" ") + p1[phrase/10 - 1];
                else
                    tmp = p1[phrase/10 - 1];
            }
            else if (phrase >= 10){
                if (tmp.length()>0)
                    tmp = tmp + string(" ") + p0[phrase - 10];
                else
                    tmp = p0[phrase - 10];
                phrase = 0;
            }

            phrase = phrase % 10;
            if (phrase > 0){
                if (tmp.length()>0)
                    tmp = tmp + string(" ") + p2[phrase - 1];
                else
                    tmp = p2[phrase - 1];
            }

            if (ucnt > 0 && cur > 0){
                tmp = tmp + string(" ") + unit[ucnt];
            }

            if (tmp.length() > 0)
                ret = tmp + string(" ") + ret;

            ucnt++;
        }

        /* trim trailing space */
        ret.resize(ret.length() - 1);

        return ret;
    }
};