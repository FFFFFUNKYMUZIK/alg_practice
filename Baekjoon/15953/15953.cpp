#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class fenwick{
    int size;
    vector<int> arr;

public :

    fenwick() = default;
    fenwick(int n): size(n), arr(n + 1, 0) {};

    void update(int i, int v){
        if (i==0) return;
        while(i <= size){
            arr[i] += v;
            i += (i&(-i));
        }
    }

    int get(int i){
        if (i==0) return 0;
        int sum = 0;
        while(i>0){
            sum += arr[i];
            i -= (i&(-i));
        }
        return sum;
    }
};



int main(void){

    int T;
    int a,b;
    int reward;

    fenwick fiesta1(100);
    fenwick fiesta2(64);

    fiesta1.update(1,500);
    fiesta1.update(1+1,-200);
    fiesta1.update(1+2+1,-100);
    fiesta1.update(1+2+3+1,-150);
    fiesta1.update(1+2+3+4+1,-20);
    fiesta1.update(1+2+3+4+5+1,-20);
    fiesta1.update(1+2+3+4+5+6+1,-10);

    fiesta2.update(1,512);
    fiesta2.update(1+1,-256);
    fiesta2.update(1+2+1,-128);
    fiesta2.update(1+2+4+1,-64);
    fiesta2.update(1+2+4+8+1,-32);
    fiesta2.update(1+2+4+8+16+1,-32);
    
    cin>>T;

    while(T-->0){
        cin>>a>>b;
        cout<<(fiesta1.get(a) + fiesta2.get(b))*10000<<endl;
    }


    return 0;
}
