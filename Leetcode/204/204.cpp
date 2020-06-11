#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
	int cnt = 0;
	if (n<=2) return 0;
	vector<char> check(n, 0);

	for (long long i=2;i<n;i++){
		if (check[i]==0){
			cnt++;
			for (long long j=i*i;j<n;j+=i){
				check[j]=1;
			}
		}
	}

	return cnt;
    }
};

int main(){


return 0;
}