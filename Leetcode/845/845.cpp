/*
Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        /* two pass : two dp arrays which represents maximum ascending subarray length w.r.t. direction */

        int n = arr.size();

        if (n<=2) return 0;

        int maxlen = 0;
        int s = 0;

        /* state: fft(default, descending), tff(ascending), ftf(descending after ascending) */ 
        bool asc = false;
        bool dsc = false;
        bool dft = true;

        arr.push_back(arr[n-1] + 1);

        for (int i=1;i<=n;i++){
        	if (arr[i] < arr[i-1]){
        		if (asc){
        			asc = false;
        			dsc = true;
        			dft = false;
        		}
        	}
        	else if(arr[i] > arr[i-1]){
        		if (dsc){
        			maxlen = max(maxlen, i - s);
        			s = i-1;
        		}
        		else if (dft){
        			s = i-1;
        		}

        		asc = true;
        		dsc = false;
        		dft = false;
        	}
        	else{
        		if (dsc){
        			maxlen = max(maxlen, i - s);	
        		}
        		asc = false;
        		dsc = false;
        		dft = true;
        	}
        }

        arr.pop_back();

        return maxlen;
    }
};