class Solution {
	#define ALP 26
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();

        if (n == 0) return len;

        using e = struct {char c; int freq;};
        vector<e> cnt(ALP, {0, 0});

        for (int i=0;i<tasks.size();i++){
        	cnt[tasks[i]-'A'].c = tasks[i];
        	cnt[tasks[i]-'A'].freq++;
        }

        using comp = struct{
        	bool operator()(const e& lhs, const e& rhs){return lhs.freq<rhs.freq;};
        };


        priority_queue<e, vector<e>, comp> pq;

        for (int i=0;i<ALP;i++){
        	if (cnt[i].freq > 0)
        		pq.push(cnt[i]);
        }

        queue<e> blocked;
        for (int i=0;i<=n;i++){
        	blocked.push({0,0});
    	}

        int job = len;
        int time = 0;

        e freed;
        e cur;

        while(job > 0){

        	freed = blocked.front();
        	blocked.pop();

        	if (freed.c != 0){
        		pq.push(freed);
        	}

        	if (!pq.empty()){
        		cur = pq.top();
        		pq.pop();
        		cur.freq--;

        		if (cur.freq > 0)
        			blocked.push(cur);
        		else
        			blocked.push({0,0});
        		
        		job--;
        	}
        	else{
        		blocked.push({0,0});
        	}

        	time++;
        }

        return time;
    }
};