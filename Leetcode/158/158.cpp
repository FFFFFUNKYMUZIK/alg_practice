/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/*
Note:

Consider that you cannot manipulate the file directly, the file is only accesible for read4 but not for read.
The read function may be called multiple times.
Please remember to RESET your class variables declared in Solution, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
It is guaranteed that in a given test case the same buffer buf is called by read.
*/

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    char pre[4];
    int len = 0;
    
    int read(char *buf, int n) {
        
        if (n<=len){
            memcpy(buf, pre, n);
            memmove(pre, pre+n, len-n);
            len-=n;
            return n;
        }
        
        int sum =0;
        
        if (len!=0){
            memcpy(buf, pre, len);
            buf+=len;
            sum+=len;
            len = 0;
        }
                
        int readnum = 4;
        char tmp[4];
        
        while(n>sum && readnum == 4){
            readnum = read4(tmp);
            sum+=readnum;
            if (sum>n) len = sum-n;
            memcpy(buf, tmp, readnum-len);
            buf+=readnum;
        }
        
        int rlen = min(sum, n);
        
        if (sum>n){
            memcpy(pre, tmp+readnum-len, len);
        }
        else{
            len=0;
        }
        
        return rlen;
    }
};