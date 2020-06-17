#include <vector>
#include <algorithm>

using namespace std;

/*
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

#if 0

//O(n) solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
	int n = nums.size();
	if (n==0) return 0;

	int st=0, en=0;
	int sum = 0;
	int len = n+1;

	while(en<n){
		sum+=nums[en];
		if (sum>=s){
			while(sum>=s) sum-=(nums[st++]);
			len = min(len, en - st + 2);
		}
		en++;
	}
        
	return len>n? 0 : len;
    }
};

#else

//O(nlogn) solution


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
	int n = nums.size();
	if (n==0) return 0;

	vector<int> psum(n, 0);
	psum[0] = nums[0];
	for (int i=1;i<n;i++){
		psum[i]=psum[i-1]+nums[i];
	}

	int len = n+1;

	for (auto it=psum.end()-1;it>=psum.begin();it--){
		if (*it<s) break;
		auto sit = upper_bound(psum.begin(), psum.end(), *it-s);
		len = min(len, int(it-sit)+1);
	}

	return len>n? 0 : len;
    }
};
#endif



int main(){

Solution sol;
vector<int> in;
int ret;

in = vector<int>({2,3,1,2,4,3});
ret = sol.minSubArrayLen(7, in);

return 0;
}