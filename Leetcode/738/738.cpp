class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int ret = 0;
        int tmp = N;
        int div = 1;
        int p, c, sdiv;

        tmp /= 10;
        while (tmp>0){
        	tmp /= 10;
        	div *= 10;
        }

        p = 0;
        while (div>0){
        	ret *= 10;
        	c = N / div;

        	if (p<c){
        		sdiv = div;
        	}
        	else if (p>c){
       			ret = (ret * div) - ((ret * div) % sdiv)  - 1;
        		return ret;
        	}

        	ret += c;
        	p = c;
        	N = N - c * div;
        	div /= 10;
        }

        return ret;
    }
};