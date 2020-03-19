#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, B, C;
	cin >> N >> B >> C;

	int idx = 0;
	unsigned long long num = 0;
	unsigned long long cur = 0;
	unsigned long long ret;

	if (C >= B) {
		while (idx < N) {
			cin >> cur;
			num += cur;
			idx++;
		}
		ret = num * B;
	}
	else {
		unsigned long long triplet = 0;
		unsigned long long doublet = 0;
		unsigned long long seed = 0;
		unsigned long long seedcnt = 0;

		while (idx < N) {
			cin >> cur;
			num += cur;

			if (cur > seed) {
				seedcnt += (cur - seed);
				triplet = doublet;
				doublet = cur - seed;
			}
			else {
				triplet = std::min(doublet, cur);
				doublet = 0;
			}
			seed = doublet + triplet;
			
			/*
			printf("%d \n", seed);
			printf("doublet %d triplet %d \n", (int)doublet, (int)triplet);
			
			cout << "seed : " << seed << endl;
			cout << "doublet : " << doublet << " triplet : " << triplet << endl;
			*/
			idx++;
		}
		ret = seedcnt * B + (num - seedcnt) * C;


		//printf("%dB %dC\n",seedcnt, num - seedcnt);
		//cout << seedcnt << "B " << num - seedcnt << "C" << endl;
	}

	cout << ret << endl;

	return 0;
}
