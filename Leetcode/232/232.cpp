class MyQueue {
public:

    int n;
    stack<int> in, out;
    /** Initialize your data structure here. */
    MyQueue() {
        n = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
        n++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (n == 0) return -1;
        int ret = peek();
        out.pop();
        n--;
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (n == 0) return -1;
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int ret = out.top();
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return n == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */