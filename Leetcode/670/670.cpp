class Solution {
public:
    int maximumSwap(int num) {

        vector<int> digits;
        int org = num;

        while(org > 0){
            digits.push_back(org%10);
            org /= 10;
        }

        int pre = 9;
        int i;

        for (i=digits.size() - 1;i>=0;i--){
            if (digits[i] > pre){
                break;
            }
            pre = digits[i];
        }

        if (i==-1) return num;

        int maxidx = 0;

        for (;i>=0;i--){
            if (digits[i] >= digits[maxidx]){
                maxidx = i;
            }
        }

        for (i=digits.size() -1;i>=0;i--){
            if (digits[i] < digits[maxidx]){
                break;
            }
        }

        int tmp = digits[i];
        digits[i] = digits[maxidx];
        digits[maxidx] = tmp;

        int ret = 0;
        for (i=digits.size() -1;i>=0;i--){
            ret *= 10;
            ret += digits[i];
        }

        return ret;

    }
};