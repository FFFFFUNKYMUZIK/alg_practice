//Pr. 1

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    int len = s.length();
    vector<int> cnt(26*2, 0);    
    string ret;
    
    for (int i=0;i<len;i++){
        if (s[i]>='a'){
            cnt[s[i]-'a']++;
        }
        else{
            cnt[s[i]-'A'+26]++;
        }
    }
    
    for (int i=25;i>=0;i--){
        for (int j=0;j<cnt[i];j++){
            ret+=('a'+i);
        }
    }
    for (int i=51;i>=26;i--){
        for (int j=0;j<cnt[i];j++){
            ret+=('A'+i-26);
        }
    }
    
    return ret;
}

//Pr. 2

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    int acc = x;
    for (int i=0;i<n;i++){
        answer.push_back(acc);
        acc+=x;
    }

    return answer;
}