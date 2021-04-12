class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;
        for (int i=0;i<n;i++){
        	sum += stones[i];
        }

        int half = sum/2;
        int maxseqsum = 0;
        vector<char> seqsum(half + 1, 0);
        seqsum[0] = 1;

        for (int i=0;i<n;i++){
        	vector<char> seqsum_tmp = seqsum;
        	for (int j=stones[i];j<=half;j++){
        		seqsum_tmp[j] = seqsum[j-stones[i]] || seqsum_tmp[j];
        		if (seqsum_tmp[j]) maxseqsum = max(maxseqsum, j);
        	}
        	seqsum.swap(seqsum_tmp);
        }

        return sum - 2 * maxseqsum;
    }
};