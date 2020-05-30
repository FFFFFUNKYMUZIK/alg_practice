#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;


#if 0

//O(n), but too complex


/*
Note: The result may be very large, so you need to return a string instead of an integer.
*/


// priority is same to alphabetical order, apply radix sort
// short length numbers are accounted to be repeated.
// ex)
//  3 3 5 2 1       priority 2
//  3 3(3 3 3...)   priority 3
//  3 4 3(3 4...)   priority 1
// nonnegative integer  < 2147483647 (max 10 digit)

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        int n = nums.size();
        unordered_map<char, list<string>> um;
        int len = 10;

        int pos = 1;
        for (int i = 0; i < n; i++) {
            string cur = to_string(nums[i]);
            um[cur[(len-pos)%cur.length()]].push_back(cur);
        }
        
        pos = 2;
        while (pos<=10) {
            unordered_map<char, list<string>> tmp;
            
            for (char c = '9'; c >= '0'; c--) {
                for (auto it = um[c].begin(); it != um[c].end(); it++) {
                    tmp[(*it)[(len-pos)% (*it).length()]].push_back(*it);
                }
            }

            pos++;
            um.swap(tmp);
        }

        string ret;
        for (char c = '9'; c >= '1'; c--) {
            for (auto it = um[c].begin(); it != um[c].end(); it++) {
                ret +=(*it);
            }
        }
        if (ret.length() == 0) ret = string("0");
        else {
            for (auto it = um['0'].begin(); it != um['0'].end(); it++) {
                ret += "0";
            }
        }

        return ret;
    }
};


#else

#include <algorithm>
//O(n*l*logn), simple

class Solution {
public:

    struct custom {
        bool operator()(const std::string& s1, const std::string& s2) {
            return s1 + s2 < s2 + s1;
        }
    };

    string largestNumber(vector<int>& nums) {

        std::vector<std::string> numvec(nums.size(), "");
        for (int i = 0; i < nums.size(); i++) {
            numvec[i] = std::to_string(nums[i]);
        }

        std::string output;

        std::sort(numvec.begin(), numvec.end(), custom());
        for (int j = nums.size() - 1; j >= 0; j--) {
            output += numvec[j];
        }

        if (output[0] == '0') {
            return "0";
        }
        return output;
    }
};

#endif


int main()
{
    
    Solution sol;
    string ret;
    vector<int> in;

    in = vector<int>({10,2});
    ret = sol.largestNumber(in);

    in = vector<int>({ 3,30,34,5,9});
    ret = sol.largestNumber(in);

    in = vector<int>({ 10,2, 99, 99, 98, 97, 72, 9, 19, 92});
    ret = sol.largestNumber(in);

    in = vector<int>({ 121,12 });
    ret = sol.largestNumber(in);

    return 0;
}
