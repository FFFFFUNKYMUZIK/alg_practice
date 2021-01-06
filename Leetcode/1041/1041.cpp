class Solution {
public:
    bool isRobotBounded(string instructions) {
   		
   		bool ret;

   		vector<vector<int>> dir(4);
   		dir[0] = {0, 1}; /* t */
   		dir[1] = {1, 0}; /* r */
   		dir[2] = {0, -1}; /* b */
   		dir[3] = {-1, 0}; /* l */

   		vector<int> pos({0,0});
   		int diridx = 0;

   		for (int i=0;i<instructions.size();i++){
   			switch(instructions[i]) {
   				case 'G':
   					pos[0] += dir[diridx][0];
   					pos[1] += dir[diridx][1];
   					break;
   				case 'L':
   					if (--diridx < 0) diridx = 3;
   					break;
   				case 'R':
   					if (++diridx > 3) diridx = 0;
   					break;
   			}
   		}

   		if ((pos[0] == 0 && pos[1] == 0) || diridx != 0){
   			return true;
   		}
   		
   		return false;
   		     
    }
};