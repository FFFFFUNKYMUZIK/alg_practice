// 9251.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LCS[1001][1001] = { 0, };

int main()
{
	string one, two;

	cin >> one >> two;
	
	for (int i = 1; i <= one.length(); i++) {
		
		for (int j = 1; j <= two.length(); j++) {
			if (one[i - 1] == two[j - 1])	LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
		}
	}
	
//	cout << one.length() << endl;
	cout << LCS[one.length()][two.length()] << endl;

	return 0;
}


