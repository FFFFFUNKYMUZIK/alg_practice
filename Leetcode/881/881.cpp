class Solution {

public:
    int numRescueBoats(vector<int>& people, int limit) {
    	int n = people.size();
    	
    	sort(people.begin(), people.end(), greater<int>());

    	int cnt = 0;
    	int i = 0;
    	int j = n - 1;
    	for (i=0;i<j;i++){
    		if (people[i] + people[j] <= limit){
    			j--;
    		}
    		cnt++;
    	}

    	if (i==j) cnt++;

        return cnt;
    }
};