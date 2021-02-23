class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     	/* k(i) = number of 1 - number of 0 in arr[0] ~ arr[i] */
     	/* k(i) = psum[i] - (i + 1 - psum[i]) = 2*psum[i] - i - 1 */
     	/* hash[k(i)] = i if the bucket is empty, else */
     	/* maxlen of array satisfying the condition ending at i : i - hash[k(i)] */

    	int n = nums.size();

    	int psum = 0;
    	int key = 0;
    	int maxlen = 0;
    	int len = 0;

    	unordered_map<int, int> hash;
    	hash[0] = -1;

	   	for (int i=0;i<n;i++){
	   		psum += nums[i];
	   		key = 2 * psum - (i + 1);
	   		if (hash.find(key) != hash.end()){
	   			len = i - hash[key];
	   		}
	   		else{
	   			hash[key] = i;
	   		}

	   		if (len>maxlen){
	   			maxlen = len;
	   		}
    	}

    	return maxlen;
    }
};