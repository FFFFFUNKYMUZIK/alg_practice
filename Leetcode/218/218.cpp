/*
Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

#if 0

//line sweep + multiset
//O(NlogN)

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        if (buildings.size() == 0) return ret;
        
        vector<pair<int, int>> key_cand;
        
        for (int i=0;i<buildings.size();i++){
            key_cand.push_back(make_pair(buildings[i][0], buildings[i][2]));
            key_cand.push_back(make_pair(buildings[i][1], -buildings[i][2]));
        }
        
        sort(key_cand.begin(), key_cand.end(), [](pair<int,int>& a, pair<int,int>& b) -> bool {if (a.first==b.first){return a.second>b.second;} return a.first<b.first; });

        multiset<int> ms;
        
        int k, h;
        
        for(int i=0;i<key_cand.size();i++){
            k = key_cand[i].first;
            h = key_cand[i].second;

            if (h>=0){
                if (ms.empty() || h>*(ms.rbegin())){
                    ret.push_back({k, h});
                }
                ms.insert(h);
            }
            else{
                h = -h;
                ms.erase(ms.find(h));            
                
                if (ms.empty()){
                    ret.push_back({k, 0});
                }
                else if (h>*(ms.rbegin())){
                    ret.push_back({k, *(ms.rbegin())});
                }
            }
            
        }
        
        return ret;
    }
};

#elif 0

//segment tree w/ lazy propagation
//range update(lazy propagation, O(logN)) & point query (O(logN))
//so O(NlogN)

class Solution {
    
    typedef struct TreeNode_t{
        int lazy;
    } TreeNode;
    
    vector<TreeNode> tree;
    
    // l, r : range limit which this node(index th) care for
    // s, e : update range
    // index : index of current tree node
    void update(int index, int l, int r, int s, int e, int val){
        if ( e < l || s > r ) return;
        if ( s <= l && r <= e){
            tree[index].lazy = max(tree[index].lazy, val);
            return;   
        }
        
        int mid = (l+r)/2;
        update(2*index, l, mid, s, e, val);
        update(2*index + 1, mid+1, r, s, e, val);
    }
    
    // l, r : range limit which this node(index th) care for
    // q : query point
    // index : index of current tree node
    int query(int index, int l, int r, int q){

        if (tree[index].lazy != 0){
            if (l!=r){ //Not a leaf node
                tree[2*index].lazy = max(tree[index].lazy, tree[2*index].lazy);
                tree[2*index + 1].lazy = max(tree[index].lazy, tree[2*index + 1].lazy);
	      tree[index].lazy = 0;
            }
        }
        
        if( l==r ){
            //leaf node case
            return tree[index].lazy;
        }
    
    //tail recursion    
    int mid = (l+r)/2;
	if ( q<=mid ) return query(2*index, l, mid, q);
	else return query(2*index + 1, mid+1, r, q);

	//Never reach here
        return 0; 
  }
        
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        if (buildings.size() == 0) return ret;
        
        int n = buildings.size();
                
        vector<int> key_cand;
        
        for (int i=0;i<buildings.size();i++){
            key_cand.push_back(buildings[i][0]);
            key_cand.push_back(buildings[i][1]);
        }
        
        sort(key_cand.begin(), key_cand.end());
        
        unordered_map<int, int> sqzmap;
        int sqzcnt = 0;
        for (int i=0;i<key_cand.size();i++){
            if (sqzmap.find(key_cand[i]) == sqzmap.end()) sqzmap[key_cand[i]] = sqzcnt++;
        }
        
        int tree_h = ceil(log2(sqzcnt)) + 1;
        tree = vector<TreeNode>((1<<tree_h) + 1, {0});
                
        for (int i=0;i<n;i++){
            update(1, 0, sqzcnt-1, sqzmap[buildings[i][0]], sqzmap[buildings[i][1]] - 1, buildings[i][2]);
        }
        
        int pre = 0;
        for (int i=0;i<2*n;i++){
            int h = query(1, 0, sqzcnt-1, sqzmap[key_cand[i]]);
            if (h!=pre){
                ret.push_back({key_cand[i], h});
            }
            pre=h;
        }
        
        return ret;
    }
};

#else
//Binary Indexed Tree(BIT, fenwick)
//refer to discussion
//update & query bit operation is reverse compared to regular BIT
//update operation to kth point affects 1~k element
//point query compare all stored value of segments which it is included. (the segment value is stored by the update of buildings which starts earlier and ends later)

class Solution {
        
    vector<int> tree;
    
    // q : update point
    // val : update value
    
    void update(int q, int val){
        while(q>0){
            tree[q] = max(tree[q], val);
            q -= q & -q;
        }
    }
        
    // q : query point
    // n : size of array = size of tree
    
    int query(int n, int q){        
        int h = 0;
        while(q<=n){
            h = max(h, tree[q]);
            q += q&-q;
        }
        return h;
    }
        
        typedef struct tri_t{
            int a,b,c;            
        } tri;
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        if (buildings.size() == 0) return ret;
        
        int n = buildings.size();
                       
        vector<tri> key_cand;
        
        for (int i=0;i<buildings.size();i++){
            key_cand.push_back({buildings[i][0], 1, i }); //up
            key_cand.push_back({buildings[i][1], 0, i }); //down
        }
        
        //sort(key_cand.begin(), key_cand.end(), [buildings](tri& l, tri& r) -> bool {if (l.a==r.a){if (l.b==r.b){ return buildings[l.c][2]>buildings[r.c][2];} return l.b>r.b;} return l.a<r.a; });
        // buildings(call by value) instead of &buildings(call by reference) make T.L.E. (copy buildings vector every calling of lambda function)
        sort(key_cand.begin(), key_cand.end(), [&buildings](tri& l, tri& r) -> bool {if (l.a==r.a){if (l.b==r.b){ return buildings[l.c][2]>buildings[r.c][2];} return l.b>r.b;} return l.a<r.a; });
        
        unordered_map<int, int> sqzmap;
        int sqzcnt = 1;
        for (int i=0;i<key_cand.size();i++){
            if (sqzmap.find(key_cand[i].a) == sqzmap.end()) sqzmap[key_cand[i].a] = sqzcnt++;
        }
        
        tree = vector<int>(sqzcnt, 0);
        
        int pre = 0;
        for (int i=0;i<2*n;i++){
            tri cur = key_cand[i];
            
            if (cur.b==1){ //up
                update(sqzmap[buildings[cur.c][1]]-1, buildings[cur.c][2]);
            }
            int h = query(sqzcnt-1, sqzmap[cur.a]);
            //printf("%d %d \n", cur.a, h);
            if (h!=pre){
                ret.push_back({cur.a, h});
                pre = h;
            }
        }
                
        return ret;
    }
};

#endif