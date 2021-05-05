#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void){
	
	int M, N;

	cin>>M>>N;

	int s = sqrt(M);

	using ll = long long;
	ll sum = 0;
	ll minval;

	if (s*s != M) s++; 
	minval = s*s;

	for (int i=s;i*i<=N;i++){
		sum += i*i;
	}

	if (sum == 0){
		cout << -1 << endl;
	}
	else{
		cout<<sum << endl;
		cout<<minval << endl;
	}
	return 0;
}