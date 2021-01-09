class RandomizedSet {

    unordered_set<int> bucket;
    int n;

    mt19937 gen;
    uniform_int_distribution<int> dis;

public:

    /** Initialize your data structure here. */
    RandomizedSet() {
        unordered_set<int>().swap(bucket);
        n = 0;

        random_device rd;
        mt19937 gen = mt19937(rd());

        dis = uniform_int_distribution<int>(0, 99);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret;
        if (bucket.find(val) != bucket.end())
            ret = false;
        else{
            bucket.insert(val);
            n++;
            ret = true;
        }
        return ret;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret;
        if (bucket.find(val) != bucket.end()){
            bucket.erase(val);
            n--;
            ret = true;
        }
        else
            ret = false;
        return ret;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rand_idx = dis(gen) * n / 100;

        unordered_set<int>::iterator it = bucket.begin();
        advance(it, rand_idx);

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */