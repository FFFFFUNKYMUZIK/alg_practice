#include <iostream>
#include <string>

using namespace std;

/*
Note: For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 0) return true;

        string refine;
        for (int i = 0; i < n; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                refine += s[i];
            }
            if ((s[i] >= 'A' && s[i] <= 'Z')) {
                refine += (s[i] - 'A' + 'a');
            }
        }
        
        n = refine.length();

        for (int i = 0; i < (n + 1) / 2; i++) {
            if (refine[i] != refine[n - 1 - i]) return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    bool ret;

    ret = sol.isPalindrome(string(""));

    ret = sol.isPalindrome(string("A man, a plan, a canal: Panama"));

    ret = sol.isPalindrome(string("race a car"));

    return 0;
}