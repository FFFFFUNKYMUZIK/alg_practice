class Solution {

	#define TPM (24*60)

public:
    int findMinDifference(vector<string>& timePoints) {

    	vector<int> b(TPM, 0);

    	auto timetoint = [](string& time)-> int{
    		int h = stoi(time.substr(0, 2));
    		int m = stoi(time.substr(3, 2));
    		return h*60 + m;
    	};

    	int maxval = 0;
    	for (int i=0;i<timePoints.size();i++){
    		b[timetoint(timePoints[i])]++;
    		maxval = max(maxval, timetoint(timePoints[i]));
    	}

    	int minval = TPM;
    	int p = maxval;
    	int tmp;

    	for (int i=0;i<b.size() - 1;i++){
    		if (b[i] == 1){
    			tmp = i-p;
    			if (tmp > TPM/2) tmp = TPM - tmp;
    			if (tmp < -TPM/2) tmp = TPM + tmp;
				minval = min(minval, abs(tmp));
				p = i;
    		}
    		else if (b[i] > 1){
    			return 0;
    		}
    	}

    	return minval;
    }
};