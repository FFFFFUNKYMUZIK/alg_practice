class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

    	int n = arr.size() + 1;
    	int s = 0, e = n - 1;
    	arr.push_back(1001);

    	while(s<e){
    		int mid = (s+e)/2;
    		int kth = arr[mid] - mid - 1;

    		if (kth < k){
    			s = mid + 1;
    		}
    		else{
    			e = mid;
    		}
    	}
    	arr.pop_back();

		return s + k;
    }
};