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

#elif 1

//segment tree w/ lazy propagation
//range update(lazy propagation, O(logN)) & point query (O(logN))
//so O(NlogN)

class Solution {
    
    typedef struct TreeNode_t{
        int lazy;
        int val;
    } TreeNode;
    
    vector<TreeNode> tree;
    
    // l, r : range limit which this node(index th) care for
    // s, e : update range
    // index : index of current tree node
    void update(int index, int l, int r, int s, int e, int val){
        if ( e < l || s > r ) return;
        if ( l <= s && e <= r){
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
        printf("l r q %d %d %d\n", l, r, q);
        if (tree[index].lazy != 0){
            printf("%d \n", tree[index].lazy);
            tree[index].val = max(tree[index].val, tree[index].lazy);
            
            if (l!=r){
                tree[2*index].lazy = max(tree[index].lazy, tree[2*index].lazy);
                tree[2*index + 1].lazy = max(tree[index].lazy, tree[2*index + 1].lazy);
            }
            tree[index].lazy = 0;
        }
        
        if( l==r ){
            return tree[index].val;
        }
        else if(q<l || r<q){
            return 0;            
        }
        
        int mid = (l+r)/2;
        return max(query(2*index, l, mid, q), query(2*index + 1, mid+1, r, q));
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
        tree = vector<TreeNode>((1<<tree_h) + 1, {0,0});
        
        
        printf("YEYEYEYEYEYE\n");
        for (int i=0;i<n;i++){
            update(1, 0, sqzcnt-1, sqzmap[buildings[i][0]], sqzmap[buildings[i][1]] - 1, buildings[i][2]);
        }
        printf("YEYEYEYEYEYE\n");
        
        int pre = 0;
        for (int i=0;i<2*n;i++){
            printf("%d\n", i);
            printf("%d\n", sqzmap[key_cand[i]]);
            int h = query(1, 0, sqzcnt-1, sqzmap[key_cand[i]]);
            printf("%d\n", h);
            if (h!=pre){
                ret.push_back({key_cand[i], h});
            }
        }
        
        return ret;
    }
};

#else
//Binary Indexed Tree(BIT, fenwick)


#endif