/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {

	using NII = struct {NestedInteger ni; int idx;};
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int wsum = 0;

        queue<NII> q;
        vector<int> b;

        auto flattener = [](vector<NestedInteger>& nestedList, queue<NII>& q, int idx){
        	for (int i=0;i<nestedList.size();i++){
        		q.push({nestedList[i], idx});
        	}
        };
        flattener(nestedList, q, 0);

        while(!q.empty()){
        	NII& cur = q.front();
        	if (b.size() == cur.idx){
        		b.push_back(0);
        	}

        	if (cur.ni.isInteger()){
        		b[cur.idx] += cur.ni.getInteger();
        	}
        	else{
        		flattener(cur.ni.getList(), q, cur.idx+1);
        	}
        	q.pop();
        }

        for (int i=0, d=b.size();i<b.size();i++, d--){
        	wsum += b[i] * d;
        }

        return wsum;
    }
};