class Solution {
public:
    int numTeams(vector<int>& rating) {
    	int n = rating.size();

    	class fw{
    		vector<int> bucket;
    		int size;

    	public:

    		fw(int n){vector<int>(n+1, 0).swap(bucket); size = n;};

    		void update(int i, int val){
    			while(i<=size){
    				bucket[i]+=val;
    				i += (i&-i);
    			}
    		}

    		int get(int i){
    			int sum = 0;
    			while(i>0){
    				sum += bucket[i];
    				i -= (i&-i);
    			}
    			return sum;
    		}
    	};

    	fw tree(100000);
    	vector<int> smaller(n, 0);

    	for (int i=n-1;i>=0;i--){
    		tree.update(rating[i], 1);
    		smaller[i] = tree.get(rating[i] - 1);
    	}

    	int cnt = 0;
    	for (int i=0;i<n;i++){
    		for (int j=i+1;j<n;j++){
    			if (rating[i] < rating[j]){
    				cnt += (n - j - 1 - smaller[j]);
    			}
    			else{
    				cnt += smaller[j];
    			}
    		}
    	}

        return cnt;
    }
};