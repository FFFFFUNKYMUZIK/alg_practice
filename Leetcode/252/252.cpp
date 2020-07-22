class Solution {
public:
    
    static bool compare(vector<int>& lhs, vector<int>& rhs){
        if (lhs[0]==rhs[0]) return lhs[1]<rhs[1];
        return lhs[0]<rhs[0];
    }
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if (n==0) return true;
        sort(intervals.begin(), intervals.end(), compare);
        
        int end=intervals[0][0];
        for (int i=0;i<n;i++){
            if (end>intervals[i][0]) return false;
            end = intervals[i][1];
        }
        
        return true;
    }
};