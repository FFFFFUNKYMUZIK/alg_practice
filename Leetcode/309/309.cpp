class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();

    	if (n<=1) return 0;

    	/* refer to state machine based solution. */
    	int reset = 0;
    	int held = INT_MIN;
    	int sold = INT_MIN;

    	int prereset;

    	/* reset : max(sold, reset) */
    	/* held : max(reset - price, held) */
    	/* sold : held + price */

    	for (int i=0;i<n;i++){
    		prereset = reset;

    		reset = max(sold, reset);
    		sold = held + prices[i];
    		held = max(prereset - prices[i], held);
    	}

		return max(reset, max(sold, held));
    }
};