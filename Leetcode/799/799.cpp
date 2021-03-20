class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

    	int i, j;

    	vector<double> row(query_row + 1, 0.0);
    	vector<double> nextrow(query_row + 1, 0.0);

    	row[0] = poured;

    	for (i=0;i<query_row;i++){
    		for (j=0;j<=i;j++){
    			if (row[j] > 1.0){
    				nextrow[j] += (row[j] - 1.0)/2.0;
    				nextrow[j+1] += (row[j] - 1.0)/2.0;
    			}
    			row[j] = 0;
    		}
    		row.swap(nextrow);
    	}

    	return min(row[query_glass], 1.0);	
    }
};