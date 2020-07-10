//Push O(n), pop/top O(1)

class MyStack {
public:
    
    int n;
    queue<int> qin,q;
    /** Initialize your data structure here. */
    MyStack() {
        n=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qin.push(x);
        while(!q.empty()){
            qin.push(q.front());
            q.pop();
        }
        qin.swap(q);
        n++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = -1;
        if (n>0){
            ret = q.front();
            q.pop();
            n--;
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int ret = -1;
        if (n>0){
            ret = q.front();
        }
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (n==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */