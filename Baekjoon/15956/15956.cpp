#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool get_tok(string& in, int s, string& out){
    string tok;
    if (in.length() == s) return false;
    
    /* variable token */
    if ((in[s] == '-') || (in[s] >= '0' && in[s] <= '9')){
        int i = 1;
        while((s+i<in.length()) && (in[s+i] >= '0' && in[s+i] <= '9')) i++;
        out = in.substr(s, i);
        return true;
    }
    else if ((in[s] >= 'a' && in[s] <= 'z') || (in[s] >= 'A' && in[s] <= 'Z')){
        int i = 1;
        while((s+i<in.length()) && ((in[s+i]>='a' && in[s+i] <= 'z') ||
                                (in[s+i] >= 'A' && in[s+i] <= 'Z'))) i++;
        out = in.substr(s, i);
    }
    else if (in[s] == '='){
        out = "==";
    }
    else if (in[s] == '!'){
        out = "!=";
    }
    else if (in[s] == '&'){
        out = "&&";
    }
    return false;
}

class UF{

    vector<int> p;

public:
    UF() = default;
    UF(int n) : p(n,0){for (int i=0;i<n;i++) p[i] = i;};

    /* index of short string MUST BE x */
    void _union(int x, int y){

        int px = _find(x);
        int py = _find(y);
        
        if (px != py){
            p[py] = px;
        }
    }

    int _find(int x){
        if (x==p[x]){
            return x;
        }
        
        return p[x] = _find(p[x]);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string f{"0==1"};
    string t{"0==0"};
    
    unordered_map<string, int> name_idx;
    unordered_map<int, bool> idx_digit;
    unordered_map<int, string> idx_name;
    unordered_map<int, string> digit;

    string S;
    cin>>S;

    int si = 0, ni = 0;
    vector<int> lvec, rvec;
    vector<char> opvec;
    string l, r, op;
    bool ld, rd;
    while(si<S.length()){
        ld = get_tok(S, si, l);
        si += l.length();
        get_tok(S, si, op);
        si += 2;
        rd = get_tok(S, si, r);
        si += r.length();

        if (name_idx.find(l) == name_idx.end()){
            name_idx[l] = ni;
            idx_digit[ni] = ld;
            if (ld) digit[ni] = l;
            lvec.push_back(ni);
            idx_name[ni++] = l;
        }
        else{
            lvec.push_back(name_idx[l]);
        }

        if (name_idx.find(r) == name_idx.end()){
            name_idx[r] = ni;
            idx_digit[ni] = rd;
            if (rd) digit[ni] = r;
            rvec.push_back(ni);
            idx_name[ni++] = r;
        }
        else{
            rvec.push_back(name_idx[r]);
        }

        opvec.push_back(op=="==");
        
        get_tok(S, si, op);
        si += 2;
    }

    string ans;
    UF uf(ni);

    for (int i=0;i< lvec.size();i++){
        if (opvec[i]){
            int p1 = uf._find(lvec[i]);
            int p2 = uf._find(rvec[i]);
            
            if (p1==p2) continue;
            if (idx_name[p1].length() < idx_name[p2].length()){
                uf._union(p1, p2);
            }
            else {
                uf._union(p2, p1);
            }
            
        }
    }

    for (int i=0;i<ni;i++){
        int p1 = uf._find(i);
        if (p1 == i) continue;
        
        if (idx_digit[i]){
            if (digit.find(p1) == digit.end()){
                digit[p1] = idx_name[i];
            }
            else{
                if (digit[p1] != idx_name[i]){
                    cout<<f<<endl;
                    return 0;
                }
                else
                    continue;
            }
        }
        
        ans += (idx_name[p1] + "==" + idx_name[i] + "&&");
    }
    
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
        }
    };
    
    unordered_set<pair<int,int>, pair_hash> us;

    for (int i=0;i<lvec.size();i++){
        if (opvec[i] == 0){
            int p1 = uf._find(lvec[i]);
            int p2 = uf._find(rvec[i]);
            if (p1 == p2){
                cout<<f<<endl;
                return 0;
            }
            else{
                if(digit.find(p1) != digit.end() && digit.find(p2) != digit.end()){
                    if (digit[p1] == digit[p2]){
                        cout<<f<<endl;
                        return 0;
                    }
                    else{
                        continue;
                    }
                }
                if ((us.find(make_pair(p1,p2)) != us.end()) || (us.find(make_pair(p2,p1)) != us.end())){
                    continue;
                }
                    
                us.insert(make_pair(p1,p2));
                ans += (idx_name[p1] + "!=" + idx_name[p2] + "&&");
            }
        }
    }
    
    if (ans.length() == 0){
        ans = t;
    }
    else{
        ans.resize(ans.length()-2);
    }
    cout<<ans<<endl;

    return 0;
}
