class Solution {
	int backtrack(vector<string>& arr, vector<int>& bitvec, int bit, int i){
		if (i == arr.size()) return 0;

		int maxval = 0;
		if (bitvec[i] != 0 && (bit & bitvec[i]) == 0){
			maxval = arr[i].length() + backtrack(arr, bitvec, bit|bitvec[i], i+1);
		}

		return max(maxval, backtrack(arr, bitvec, bit, i+1));
	}

public:

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> bitvec(n, 0);

        for (int i=0;i<n;i++){
        	int bit = 0;
        	for (int j=0;j<arr[i].length();j++){
        		if (bit & (1<<(arr[i][j] - 'a'))){
        			bit = 0;
        			break;
        		}
        		bit |= (1<<(arr[i][j] - 'a'));
        	}
        	bitvec[i] = bit;
        }

        return backtrack(arr, bitvec, 0, 0);
    }
};