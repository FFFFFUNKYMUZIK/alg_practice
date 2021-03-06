#include "stdafx.h"
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

	typedef struct hasher_t {

		template <class T1, class T2>
		size_t operator()(const pair<T1, T2>& key) const {
			//standard hasher for T1, T2
			/*
			auto h1 = std::hash<T1>()(key.first);	//also possible
			auto h2 = std::hash<T2>()(key.second); //also possible
			*/
			auto h1 = std::hash<T1>{}(key.first);
			auto h2 = std::hash<T2>{}(key.second);
			
			return h1 ^ (h2 - 1);
		}

	} hasher;

	
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return string("0");
		long long sign = numerator * (long long)denominator;

		string ret = sign > 0 ? "" : "-";

		long long ldeno = abs((long long)denominator);
		long long q = abs(numerator / ldeno);
		long long r = abs(numerator % ldeno);
		
		
		ret = ret + to_string(q) + ".";
		unordered_map<pair<long, long>, int, hasher> index_hash;
		vector<int> qarr;
		int pos = 0;
		int rep = -1;

		while (r) {
			r *= 10;
			while (r < ldeno) {
				r *= 10;
				qarr.push_back(0);
				pos++;
			}
			q = r / ldeno;
			r = r % ldeno;
			if (index_hash.find(make_pair(q, r))!= index_hash.end()) {
				rep = index_hash[make_pair(q, r)];
				break;
			}
			else {
				index_hash[make_pair(q, r)] = pos++;
				qarr.push_back(q);
			}
		}

		if (rep != -1) {
			for (int i = 0; i < rep; i++) {
				ret += to_string(qarr[i]);
			}
			ret += "(";
			for (int i = rep; i < pos; i++) {
				ret += to_string(qarr[i]);
			}
			ret += ")";
		}
		else {
			for (int i = 0; i < pos; i++) {
				ret += to_string(qarr[i]);
			}
			if (pos == 0) {
				ret = sign > 0 ? "" : "-";
				ret += to_string(q);
			}
		}
		
		return ret;
	}
};

int main()
{
	Solution sol;
	string ret;

	ret = sol.fractionToDecimal(1, 2);

	ret = sol.fractionToDecimal(2, 1);

	ret = sol.fractionToDecimal(2, 3);

	ret = sol.fractionToDecimal(-50, 8);

	ret = sol.fractionToDecimal(10001, 9999);

	//this doesn't make error
	ret = sol.fractionToDecimal(-2147483647 - 1, 1);

	//but this makes error(error C4146)
	//ret = sol.fractionToDecimal(-2147483648, 1);

    return 0;
}

