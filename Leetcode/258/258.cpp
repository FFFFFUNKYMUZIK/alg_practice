/*

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

*/

class Solution {
public:
    int addDigits(int num) {
        
        //138->12->3
        //139->13->4
        //140->5
        //141->6
        //145->1
        //999999999990->99->18->9
        //999999999991->100->1
        //999999999999->108->9
        //399999 -> 48 -> 12 -> 3
        //400000 -> 4
                
        //x -> y
        //x+1 -> y+1?
        
        //y=f(x)
        //x%9 == f(x)?
        //f(x) = g(g(g(...g(x))))
        //x%9 == g(x)%9?
        //where g(x)=sigma(all digits of x);
        //proof)
        //x = sigma(10^i * a_i)
        //x = sigma(a_i) (mod 9)
        //x = g(x) = g(g(x)) = ... = f(x) (mod 9)
        if (num==0) return 0;        
        return num%9 == 0 ? 9 : num%9;
        
    }
};