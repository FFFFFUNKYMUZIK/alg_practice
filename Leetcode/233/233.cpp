//O(log10(N))
class Solution {
public:
    int countDigitOne(int n) {

        long long nl = n;
        long long div = 10;

        int cnt = 0;
        int digit;

        while (div <= 10 * nl) {
            digit = nl % div - nl % (div / 10);
            cnt += (nl / div) * (div / 10) + (digit >= 1) * (min(nl % div - div / 10, div / 10 - 1) + 1);
            div *= 10;
        }

        return cnt;
    }
};