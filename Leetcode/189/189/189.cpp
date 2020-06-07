#include <iostream>
#include <vector>

using namespace std;

/*
Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

/*
Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0
*/

#if 1

//solution 1
//using GCD(greatest common denominator) & cyclic swap
//T.C. O(n), S.C. O(1)

class Solution {
public:

    int getGCD(int a, int b) {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }

    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0 || n <= 1) return;
        int nthread = getGCD(n, k);

        for (int i = 0; i < nthread; i++) {
            int j = (i + k) % n;
            while (j != i) {
                swap(nums[i], nums[j]);
                j = (j + k) % n;
            }
        }
    }
};

#elif 0

#include <vector>

//solution 2
//use additional memory
//T.C. O(n+k) = O(n), S.C. O(n-k) = O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0 || n <= 1) return;

        vector<int> tmpv;
        tmpv.resize(n-k);

        int i = 0;

        for (; i < n-k; i++) {
            tmpv[i] = nums[i];
        }
        for (; i < n; i++) {
            nums[i - n + k] = nums[i];
        }
        int j = 0;
        for (i = k; i < n; i++, j++) {
            nums[i] = tmpv[j];
        }
    }
};


#else

//solution 3
//reverse the vector so that two partial vectors which is devided at (n-k)th position swap their order, and reverse the partial vectors to recover its original order
//use swap for doing it in-place
//T.C. O(n), S.C. O(1)

class Solution {
public:

    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0 || n <= 1) return;
        
        int i = 0;
        int half = n / 2, tmp;
        for (; i < half; i++) {
            swap(nums[i], nums[n - 1 - i]);
        }

        for (i = 0; i < k/2; i++) {
            swap(nums[i], nums[k - 1 - i]);
        }
        int j = 0;
        for (i=k; i < k+(n-k)/2; i++, j++) {
            swap(nums[i], nums[n - 1 - j]);
        }

    }
};



#endif

int main()
{
    Solution sol;

    vector<int> in;

    in = vector<int>({1,2,3,4,5,6,7});
    sol.rotate(in, 3);

    in = vector<int>({ -1,-100,3,99 });
    sol.rotate(in, 2);

    return 0;
}
