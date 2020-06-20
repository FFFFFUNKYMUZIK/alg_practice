#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int len = phone_book.size();
    unordered_set<string> us;
    
    for (int i=0;i<len;i++){
        string& cur = phone_book[i];
        if (us.find(cur) != us.end()){
            return false;
        }
        us.insert(cur);
    }
    
    for (int i=0;i<len;i++){
        string& cur = phone_book[i];
        int slen = cur.length();
        string curp;
        for (int j=1;j<slen;j++){
            curp = cur.substr(0,j);
            if (us.find(curp) != us.end()){
                return false;
            }
        }
    }

    return answer;
}