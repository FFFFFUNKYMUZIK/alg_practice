#include <vector>
#include <string>

using namespace std;



/*

Note:

1. All inputs are consist of lowercase letters a-z.
2. The values of words are distinct.


*/
/*

dfs time complexity(from one node)

O(4*V) = O(MN)

brute force (L : number of words)

O((MN)^2 * L)

Trie ( len : max length of word from words)

O((MN)^2 + L*len)

*/

class Solution {

private:
    
vector<vector<char>> boardref;
vector<vector<bool>> visit;
int m, n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> cand;

    
class Trie {
	private:
	vector<Trie*> nxt;
	int index;

	public:
	Trie(){vector<Trie*>(26, nullptr).swap(nxt); index = -1;}
	~Trie(){for (int i=0;i<nxt.size();i++)if(nxt[i]){delete nxt[i];} }
	void setindex(int i){index = i;}
    int getindex(){return index;}
	Trie* setnext(char a){
		if (a>'z' || a<'a') return nullptr;
		if (!nxt[a-'a']){	
			nxt[a-'a'] = new Trie();
		}
		return nxt[a-'a'];
	}
	Trie* getnext(char a){
		return nxt[a-'a'];
	}
};

    
void insert(Trie* proot, string word, int i){
	Trie* pt = proot;
	for (int k=0;k<word.length();k++){
		pt = pt->setnext(word[k]);
	}
	pt->setindex(i);
}

void dfs(int i, int j, Trie* pt){
     
	visit[i][j] = true;
    
    Trie* npt = pt->getnext(boardref[i][j]);
    
    if (!npt){
        visit[i][j] = false;
        return;
    }
    
    int index;
    if ((index = npt->getindex())>=0){
        cand[index]=1;
    }
    
	int ni, nj;
	    
	for(int k=0;k<4;k++){
		ni = i+dx[k];
		nj = j+dy[k];
		if (ni>=0 && ni<m &&
		nj>=0 && nj<n &&
		!visit[ni][nj]
		){
			dfs(ni, nj, npt);
		}
	}
    
    visit[i][j] = false;

}

Trie root;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	vector<string> ret;
	root = Trie();
	Trie* proot = &root;

	m = board.size();
	if (m==0) return ret;
	n =  board[0].size();
	if (n==0) return ret;

	int l  = words.size();
	if (l==0) return ret;

	boardref = board;
	vector<int>(l, 0).swap(cand);
    vector<vector<bool>>(m, vector<bool>(n, false)).swap(visit);

	for (int i=0;i<l;i++){
		insert(proot, words[i], i);
	}

	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			dfs(i,j,proot);
		}
	}
        
        for (int i=0;i<l;i++){
            if (cand[i]>0) ret.push_back(words[i]);
        }
        
        return ret;
    }
};



int main(){

Solution sol;
vector<vector<char>> board;
vector<string> words, out;

board = vector<vector<char>> ({  {'o','a','a','n'},
  {'e','t','a','e'},
  {'i','h','k','r'},
  {'i','f','l','v'} });

words = vector<string>( { "oath", "pea", "eat", "rain" } );

out  = sol.findWords(board, words);

return 0;

}