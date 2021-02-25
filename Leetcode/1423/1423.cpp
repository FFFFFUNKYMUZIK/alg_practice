class Solution {

	using ull = unsigned long long;
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ret = 0;
        int n = cardPoints.size();

        ull sum = 0;
        ull minsum = 0;
        ull rangesum = 0;

        for (int i=0;i<n-k;i++){
        	sum += cardPoints[i];
        	minsum += cardPoints[i];
        	rangesum += cardPoints[i];
        }

        for (int i=n-k;i<n;i++){
        	sum += cardPoints[i];
        	rangesum += (cardPoints[i] - cardPoints[i - n + k]);
        	minsum = min(minsum, rangesum);
        }

        return sum - minsum;
    }
};