//linear search & bin search
//O(MlogN) or O(NlogM)

#if 0
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        if (n==0) return false;
        
        for (int i=0;i<m;i++){
            if (target<matrix[i][0]) break;
            if (matrix[i][0]<= target && target<=matrix[i][n-1]){
            
                vector<int> & tvec = matrix[i];
                int s=0, e=n-1;
                while(s<=e){
                    int mid =(s+e)/2;
                    
                    if (tvec[mid]==target){
                        return true;
                    }
                    else if (tvec[mid]<target){
                        s = mid+1;
                    }
                    else{
                        e = mid-1;
                    }    
                }
            }
            
        }
        
        return false;
    }
};

#else

//2D lienar probing
//O(N+M)
// M(i,j)<=M(i',j') iff i<=i', j<=j'

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        if (n==0) return false;
        
        int i=0, j=n-1;
        while(i<m && j>=0){
            int a = matrix[i][j];
            if (a<target) {
                i++;
            }
            else if (a>target){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

#endif