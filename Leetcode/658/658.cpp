class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
    	auto it = lower_bound(arr.begin(), arr.end(), x);

    	int i, j;
    	i = j = (it - arr.begin());

    	if (i==n || (i > 0 && abs(arr[i] - x) >= abs(arr[i-1] - x))){
    		i--;
    		j--;
    	} 

    	int cnt = 1;

    	while(cnt < k){
    		if (i > 0 && j < n-1){
    			if (abs(arr[i - 1] - x) > abs(arr[j + 1] - x)){
    				j++;
    			}
    			else{
    				i--;
    			}
    		}
    		else if(i == 0){
    			j++;
    		}
    		else{
    			i--;
    		}
    		cnt++;
    	}

    	vector<int> ret(arr.begin() + i, arr.begin() + j + 1);

    	return ret;
    }
};