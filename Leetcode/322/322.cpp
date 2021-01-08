class Solution {
public:

	vector<int> dp;

	int coins_num(vector<int>& coins, int amount){
		int& ret = dp[amount];
		if (ret != 0){
			return ret;
		}

		ret = -1;

		int tmp;
		for (int i=0;i<coins.size();i++){
			if (amount - coins[i] > 0){
				if ((tmp = coins_num(coins, amount - coins[i])) != -1){
					if (ret == -1){
						ret = tmp + 1;
					}
					else{
						ret = min(ret, tmp + 1);
					}
				}
			}
			else break;
		}

		return ret;
	}

    int coinChange(vector<int>& coins, int amount) {
        /* naive DP : O(amount*C) */
        if (amount == 0) return 0;

        int cnt = 0;
    	dp = vector<int>(amount + 1 , 0);
    	sort(coins.begin(), coins.end());
    	for (int i=0;i<coins.size();i++){
    		if (coins[i] <= amount){
    			dp[coins[i]] = 1;
    			cnt++;
    		}
    		else break;
    	}
    	if (cnt == 0) return -1;

    	return coins_num(coins, amount);
    }
};