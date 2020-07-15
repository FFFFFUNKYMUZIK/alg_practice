class TwoSum {
public:
    
    unordered_map<int, int> hash;
    
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (hash.find(number) != hash.end()){
            hash[number]++;
        }
        else{
            hash[number] = 1;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for (auto it = hash.begin();it!=hash.end();it++){
            
            int num = it->first;
            
            if (hash.find(value-num) != hash.end()){
                if (value-num==num && hash[num]<2) continue;
                else{
                    return true;
                }
            }
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */