#include <iostream>
#include <vector>

using namespace std;

/*
Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

class MinStack {
public:

    vector<pair<int, int>> bucket;

    /** initialize your data structure here. */
    MinStack() {
        bucket.reserve(10);
    }

    void push(int x) {
        if (bucket.size() == 0) {
            bucket.push_back(make_pair(x, x));
        }
        else {
            int minval = bucket.back().second;
            if (minval < x) {
                bucket.push_back(make_pair(x, minval));
            }
            else {
                bucket.push_back(make_pair(x, x));
            }
        }
    }

    void pop() {
        bucket.pop_back();
    }

    int top() {
        return bucket.back().first;
    }

    int getMin() {
        return bucket.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    int ret;
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    ret = minStack.getMin(); // return -3
    minStack.pop();
    ret = minStack.top();    // return 0
    ret = minStack.getMin(); // return -2

    return 0;
}