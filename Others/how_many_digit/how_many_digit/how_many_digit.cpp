#include <iostream>

//return how many given digit appears from a to b
//T.C. : 1 ~ 10000, 8
//return : 4000 = 4*1000/10 (WLOG)
//constraint : a, b is positive and a<b, d is positive single digit(1~9)
//time complexity O(log2(ab))
int solution(int a, int b, int d) {
    if (a > b || d<1 || d>9) return 0;
    if (a != 1) return solution(1, b, d) - solution(1, a, d);

    int div = 10;
    int pack = 1;
    int ret = 0;
    int q, r, pre;

    while (div < b * 10) {
        q = b / div;
        r = b % div;
        ret += q * pack;

        pre = r / (div / 10);
        if (pre > d) ret += pack;
        else if (pre == d) ret += r%(div/10) + 1;
                
        pack *= 10;
        div *= 10;
    }

    return ret;

}

int main()
{
    int ret;

    ret = solution(1, 10000, 8);

    ret = solution(1, 9997, 8);

    ret = solution(4, 558, 2);

    ret = solution(1, 896, 8);

    return 0;

}
