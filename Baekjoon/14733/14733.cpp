#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ASIDE 50000
#define SIDE (2*ASIDE)

using namespace std;

/*

class node {
public:
	int lazy;
    int sum;

	node() : lazy(0), sum(0) {}
};


class segtree{

	vector<node> tree;
    int leaf;

public:
	segtree(int leaf_){
        leaf = leaf_;

		int h = log2(leaf_) + 1;
		int seg_nodes = 1<<(h+1) + 1;

		tree = vector<node>(seg_nodes, node());
	}

	void update(int l, int r, int s, int e, int n, int diff){

        if (l<=s && e<=r){
            tree[n].lazy += diff;
        }
        
        if (tree[n].lazy != 0){
            tree[n].sum += tree[n].lazy * (e - s + 1);
            if (s!=e){
                tree[2*n].lazy += tree[n].lazy;
                tree[2*n + 1].lazy += tree[n].lazy;
            }
            tree[n].lazy = 0;
        }

        if ((l<=s && e<=r) || (e<l || r<s)) return;

        int m  = (s + e)/2;

        update(l, r, s, m, 2*n, diff);
        update(l, r, m+1, e, 2*n + 1, diff);

        tree[n].sum = tree[2*n].sum + tree[2*n+1].sum;
	}

	int sum(int l, int r, int s, int e, int n){

        if (tree[n].lazy != 0){
            tree[n].sum += tree[n].lazy * (e - s + 1);
            if (s!=e){
                tree[2*n].lazy += tree[n].lazy;
                tree[2*n + 1].lazy += tree[n].lazy;
            }
            tree[n].lazy = 0;
        }

        if (l<=s && e<=r) return tree[n].sum;
        if (e<l || r<s) return 0;

        int m = (s + e)/2;
        return sum(l, r, s, m, 2*n) + sum(l, r, m+1, e, 2*n + 1);
	}

    int sumset(void){
        int cnt = 0;
        for (int i=0;i<leaf;i++){
            cnt += (sum(i, i, 0, leaf - 1, 1) > 0);
        }
        return cnt;
	}
};

*/

class segtree{

	vector<int> tree;
    vector<int> cnt;
    int leaf;

public:
	segtree(int leaf_){
        leaf = leaf_;

		int h = log2(leaf_) + 1;
		int seg_nodes = 1<<(h+1) + 1;

		tree = vector<int>(seg_nodes, 0);
        cnt = vector<int>(seg_nodes, 0);
	}

	void update(int l, int r, int s, int e, int n, int diff){

        if (e<l || r<s) return;

        if (l<=s && e<=r){
            cnt[n] += diff;
        }
        else{
            int m  = (s + e)/2;

            update(l, r, s, m, 2*n, diff);
            update(l, r, m+1, e, 2*n + 1, diff);
        }

        if (cnt[n] > 0){
            tree[n] = e - s + 1;
        }
        else{
            if (s==e){
                tree[n] = 0;
            }
            else{
                tree[n] = tree[2*n] + tree[2*n+1];
            }
        }
	}

    int sumset(void){
        return tree[1];
	}
};


using pii = pair<int, int>;
using verp = pair<pair<int, pii>, int>; 

bool comp(verp& lhs, verp& rhs){
    return lhs.first.first < rhs.first.first;
}

int main(){

	int N;
	cin>>N;

	vector<verp> vert(2*N);

    int idx = 0;
    int vertidx = 0;
    int x1, y1, x2, y2;
    while(idx < N){
        cin>>x1>>y1>>x2>>y2;
        vert[vertidx++] = make_pair(make_pair(x1, make_pair(y1, y2)), 1);
        vert[vertidx++] = make_pair(make_pair(x2, make_pair(y1, y2)), -1);
        idx++;
    }

    /* O(NlogN) */
    sort(vert.begin(), vert.end(), comp);

    segtree st(SIDE);
    
    idx = 0;
    long long area = 0;
    int prev_x = vert[0].first.first;


    /* O(NlogM)*/
    for (int i=0;i<vert.size();i++){
        verp& cur = vert[i];
        area += st.sumset() * (long long)(cur.first.first - prev_x);
        st.update(cur.first.second.first + ASIDE, cur.first.second.second + ASIDE - 1, 0, SIDE - 1, 1, cur.second);
        prev_x = cur.first.first;
    }

    cout<<area;

	return 0;
}