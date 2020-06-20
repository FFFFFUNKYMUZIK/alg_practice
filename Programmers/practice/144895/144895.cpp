//Pr. 1
#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    int len = s.length();
    stack<char> st;
    
    for (int i=0;i<len;i++){
        char& cur = s[i];
        if (!st.empty() && st.top()==cur){
            st.pop();
        }
        else{
            st.push(cur);
        }
    }
    
    return st.empty();
}


//Pr. 2

#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int,int> pii;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    stack<pii> st;
    
    int len = prices.size();
    answer.resize(len);
    
    st.push(make_pair(prices[0], 0));
    
    pii cur;
    for (int i=1;i<len;i++){
        while (!st.empty() && st.top().first>prices[i]){
            cur = st.top();
            answer[cur.second] = i-cur.second;
            st.pop();
        }
        st.push(make_pair(prices[i], i));
    }
    
    while(!st.empty()){
        cur = st.top();
        answer[cur.second] = len - 1 - cur.second;
        st.pop();
    }
    
    return answer;
}
