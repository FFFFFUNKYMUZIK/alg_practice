
using namespace std;

class Solution {
    using ui=unsigned int;
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0;
        
        ui lbit;
        ui M=m, N=n;

        while(M){
            lbit = M & -M;
            if (N<M+lbit) ret+=lbit;            
            M-=lbit;
        }
        
        return ret;
    }
};
int main(){

	return 0;
}
