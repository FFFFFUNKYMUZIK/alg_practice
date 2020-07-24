class Solution {
public:
    
    static bool compare(vector<int>& lhs, vector<int>& rhs){
        if (lhs[0]==rhs[0]) return lhs[1]<rhs[1];
        return lhs[0]<rhs[0];
    }
        
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
                
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int maxroom = 0;
        int cur = 0;
                
        //O(Nlog(N))
        for (int i=0;i<intervals.size();i++){
            vector<int>& currange = intervals[i];
            while(!pq.empty()&& pq.top()<=currange[0]){
                cur--;
                pq.pop();
            }
            pq.push(currange[1]);
            cur++;
            if (cur>maxroom) maxroom = cur;
        }
        
        return maxroom;
    }
};