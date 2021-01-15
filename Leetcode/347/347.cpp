class Solution {
	/*
	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
	It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
	You can return the answer in any order.
	*/

	using e = struct {int val;int freq;};

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        int n = nums.size();

        for (int i=0;i<n;i++)
        	hash[nums[i]]++;
        
        vector<e> buc(hash.size(), {0,0});
        int i = 0;
        for (auto a : hash)
        	buc[i++] = {a.first, a.second};

        auto comp = [](const e& lhs, const e& rhs){return lhs.freq > rhs.freq;};
        sort(buc.begin(), buc.end(), comp);

        vector<int> ret(k);
        for (int i=0;i<k;i++){
        	ret[i] = buc[i].val;
    	}

        return ret;
    }
};