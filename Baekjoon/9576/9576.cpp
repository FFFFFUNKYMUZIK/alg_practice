//
//  main.cpp
//  test
//
//  Created by 최재훈 on 2021/05/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    
	int T;

	cin>>T;
	int N,M;

	using range = struct {int a; int b;};
	using comp = struct comp{
		bool operator()(range& lhs, range& rhs){
			if (lhs.b == rhs.b){
				return lhs.a<rhs.a;
			}
			return lhs.b<rhs.b;
		}
	};

	while(T-->0){

		cin>>N>>M;
		int a,b;

		vector<range> Mvec(M, {0,0});
		for (int i=0;i<M;i++){
			cin>>a>>b;
			Mvec[i] = {a,b};
		}

		sort(Mvec.begin(), Mvec.end(), comp());

		vector<char> pick(N + 1, 0);
		int ans = 0;

		for (int i=0;i<M;i++){
			range& c = Mvec[i];
			for (int j=c.a;j<=c.b;j++){
				if (pick[j] == 0){
					pick[j] = 1;					
					ans++;
					break;
				}
			}
		}

		cout<<ans<<endl;

	}

    return 0;
}
