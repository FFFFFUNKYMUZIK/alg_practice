class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
    	int m_max =0, p_max = 0;
    	int tmp;
    	int ans = 0;

    	for (int i=0;i<nums.size();i++){
    		if (nums[i] < 0){
    			tmp = p_max;
    			p_max = m_max == 0 ? 0 : m_max + 1;
    			m_max = tmp + 1;
    		}
    		else if (nums[i] > 0){
    			p_max++;
    			m_max = m_max == 0 ? 0 : m_max + 1;
    		}
    		else{
    			p_max = 0;
    			m_max = 0;
    		}

    		ans = max(ans, p_max);
    	}

    	return ans;
    }
};