
/*
example of cycle:
17
50
25
29
85 <
89
145
42
20
4
16
37
58 <
89
*/
#include <unordered_set>

class Solution {

int process(int n){
	int ret=0;
	int digit;
	while(n){
	digit = n%10;
	ret+=digit*digit;
	}
}

public:
    bool isHappy(int n) {
	unordered_set<int>  bucket;

	while(1){
		if (n==1) return  true;
		if (bucket.find(n) != bucket.end()) return false;
		else{
			bucket.insert(n);
		}
		n = process(n);
	}
	
	return false;
    }
};

int main(){

return 0;
}

