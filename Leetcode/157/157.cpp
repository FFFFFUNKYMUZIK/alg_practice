/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/*
Note:

Consider that you cannot manipulate the file directly, the file is only accesible for read4 but not for read.
The read function will only be called once for each test case.
You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
*/

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        
        char tmp[4];
        int trying = n/4;
        int readnum = 4;
        int sum = 0;
        
        while(trying-->=0 && readnum==4 && sum<n){
            readnum=read4(buf);
            sum += readnum;
            buf+=4;
        }
        int len = min(sum, n);
        
        buf[len] = '\0';
        
        return len;
    }
};