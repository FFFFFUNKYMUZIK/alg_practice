#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	int len = participant.size();
	if (len == 0) return answer;

	unordered_map<string, int> um;

	for (int i = 0; i < len; i++) {
		if (um.find(participant[i])!= um.end()) {
			um[participant[i]]++;
		}
		else {
			um[participant[i]] = 1;
		}
		
	}
	for (int i = 0; i < len - 1; i++) {
		um[completion[i]]--;
		if (um[completion[i]] == 0) {
			um.erase(completion[i]);
		}
	}

	answer = (*(um.begin())).first;

	return answer;
}

int main()
{
	string ret;
	vector<string> p, c;
	p = vector<string>({ "leo", "kiki", "eden" });
	c = vector<string>({ "eden", "kiki", });
	ret = solution(p, c);

	p = vector<string>({ "marina", "josipa", "nikola", "vinko", "filipa" });
	c = vector<string>({ "josipa", "filipa", "marina", "nikola" });
	ret = solution(p, c);

	p = vector<string>({ "mislav", "stanko", "mislav", "ana" });
	c = vector<string>({ "stanko", "ana", "mislav" });
	ret = solution(p, c);



	return 0;
}
