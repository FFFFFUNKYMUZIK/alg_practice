
/* least move.. */
#if 0
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
		
		/* for x = "abcd", index is a*1000 + b*100 + c*10 + d */
		#define IDX(x) stoi(x)
    	vector<int> nodes(10000, 10000);

    	for (int i=0;i<deadends.size();i++){
    		nodes[IDX(deadends[i])] = -1;
    	}

    	if (nodes[IDX(target)] == -1) return -1;

    	nodes[0] = 0;

    	int trial = 1;
    	queue<int> q;
    	q.push(0);

    	while(!q.empty() && nodes[IDX(target)] == 10000){
    		queue<int> tmpq;
    		while(!q.empty()){
    			int cur = q.front();
    			int l, r;
    			int div = 1;
    			for (int i=0;i<4;i++){
    				l = cur - div;
    				r = cur + div;

    				while(l>=(cur - cur%(10*div)) && nodes[l] != -1){
    					if (trial < nodes[l]){
    						nodes[l] = trial;
    						tmpq.push(l);
    					}
    					l-=div;
    				}
    				while(r<=(cur - cur%(10*div) + (10*div - 1)) && nodes[r] != -1){
    					if (trial < nodes[r]){
    						nodes[r] = trial;
    						tmpq.push(r);
    					}
    					r+=div;
    				}

    				div *= 10;
    			}
    			q.pop();
    		}
    		q.swap(tmpq);
    		trial++;
    	}

    	if (nodes[IDX(target)] == 10000) return -1;

    	return nodes[IDX(target)];
    }
};
#else

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
		
		/* for x = "abcd", index is a*1000 + b*100 + c*10 + d */
		#define IDX(x) stoi(x)
    	vector<int> nodes(10000, 10000);

    	for (int i=0;i<deadends.size();i++){
    		nodes[IDX(deadends[i])] = -1;
    	}

    	if (nodes[IDX(target)] == -1 || nodes[0] == -1) return -1;

    	nodes[0] = 0;
    	int trial = 1;
    	queue<int> q;
    	q.push(0);

    	while(!q.empty() && nodes[IDX(target)] == 10000){
    		queue<int> tmpq;
    		while(!q.empty()){
    			int cur = q.front();
    			int l, r;
    			int div = 1;
    			for (int i=0;i<4;i++){
    				int digit = (cur%(10*div)) / div;

    				l = (digit+9) % 10;
    				r = (digit+1) % 10;

    				l = (cur + (l-digit)*div);
    				r = (cur + (r-digit)*div);

    				if (nodes[l] == 10000){
    					nodes[l] = trial;
    					tmpq.push(l);
    				}

    				if (nodes[r] == 10000){
    					nodes[r] = trial;
    					tmpq.push(r);
    				}

    				div *= 10;
    			}
    			q.pop();
    		}
    		q.swap(tmpq);
    		trial++;
    	}

    	if (nodes[IDX(target)] == 10000) return -1;

    	return nodes[IDX(target)];
    }
};

#endif