class MedianFinder {

	int size;
	priority_queue<int> l, r;
	double median;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
        median = 0.0;
    }
    
    void addNum(int num) {
     	int p,q;

     	if (size==0){
     		l.push(num);
     		median = (double)num;
     	}
     	else if (size % 2 == 0){
     		p = l.top();
     		q = -r.top();
     		if (num < q){
     			l.push(num);
     			median = (double)l.top();
     		}
     		else if (num >= q){
     			r.push(-num);
    			median = (double)-r.top();
     		}
     	}
     	else{
     		if (l.size() == (size + 1)/2){
     			if (num > l.top()){
     				r.push(-num);
     				median = (l.top() - r.top()) / (double)2.0;
     			}
     			else{
     				r.push(-l.top());
     				l.pop();
     				l.push(num);
     				median = (l.top() - r.top()) / (double)2.0;
     			}
     		}
     		else{
     			if (num < -r.top()){
     				l.push(num);
     				median = (l.top() - r.top()) / (double)2.0;
     			}
     			else{
     				l.push(-r.top());
     				r.pop();
     				r.push(-num);
     				median = (l.top() - r.top()) / (double)2.0;
     			}
     		}
     	}

     	size++;
    }
    
    double findMedian() {
        return median;
    }


};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */