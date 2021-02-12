class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    	unordered_map<string, string> nhash;

    	vector<vector<string>> ret;
    	unordered_map<string, int> visit;
    	unordered_map<string, vector<string>> graph; 

    	for (auto e : accounts){
    		string& name = e[0];
    		for (int i = 1 ; i < e.size() ; i++){
    			graph[e[1]].push_back(e[i]);
	    		graph[e[i]].push_back(e[1]);
	    		nhash[e[i]] = name;
	    	}	
    	}

    	stack<string> st;

    	for (auto it = graph.begin();it!=graph.end();it++){
    		const string& mail = it->first;
    		vector<string>& next = it->second; 
    		if (visit.find(mail) == visit.end()){
    			st.push(mail);
    			string cur;
    			vector<string> mails;
    			while(!st.empty()){
    				cur = st.top();
    				st.pop();

    				if (visit.find(cur) == visit.end()){
    					visit[cur] = 1;
    					mails.push_back(cur);
    					for (auto t : graph[cur]){
    						if (visit.find(t) == visit.end())
    							st.push(t);
    					}
    				}
    			}
    			sort(mails.begin(), mails.end());
    			mails.insert(mails.begin(), nhash[mail]);

    			ret.push_back(mails);
    		}
    	}

    	return ret;
    }
};