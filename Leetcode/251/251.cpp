/*
Follow up:

As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

class Vector2D {
public:
    
    vector<vector<int>>::iterator it;
    vector<vector<int>>::iterator end;
    vector<int>::iterator subit;
    vector<int>::iterator subend;
    
    Vector2D(vector<vector<int>>& v) {
        it = v.begin();
        end = v.end();
        while(it!=end && it->empty()){
            it++;
        }
        if (it!=end){
            subit = it->begin();
            subend = it->end();
        }
    }
    
    int next() {
        if (hasNext()){
            int ret = *subit;
            if (++subit == subend){
                it++;
                while(it!=end && it->empty()) it++;
                if (it!=end){
                    subit = it->begin();
                    subend = it->end();
                }
            }
            return ret;
        }
        return -1;
    }
    
    bool hasNext() {
        return it!=end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */