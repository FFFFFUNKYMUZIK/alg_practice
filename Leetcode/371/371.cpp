class Solution {
	using ll = long long;
public:
    int getSum(int a, int b) {
        
        ll x = a;
        ll y = b;
        ll x2, y2;
        ll tmp;

        if (x<y){
        	tmp = x;
        	x = y;
        	y = tmp;
        }

		/* x>=y */
        if (x*y < 0){
        	y = -y;
        	while(y>0){
        		x2 = x^y;
        		y2 = ((~x)&y)<<1;

        		x = x2;
        		y = y2;
        	}
        }
        else if(x*y > 0){
        	int sign = 0;
        	if (x<0) sign = -1;
        	x = abs(x);
        	y = abs(y);

        	while(y>0){
        		x2 = x^y;
        		y2 = (x&y)<<1;

        		x = x2;
        		y = y2;
        	}

        	if (sign) x = -x;
        }
        else if (x==0 || y==0){
        	if (x==0)
        		x = y;
        }

        return x;
    }
};