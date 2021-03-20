class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

    	int f = INT_MAX, s = INT_MAX;

		for (auto e : nums){
			if (e <= f){
				f = e;
			}
			else if (e <= s){
				s = e;
			}
			else{
				return true;
			}
		}

		return false;

    }
};