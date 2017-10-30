// you can use includes, for example:
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

int map[27][27];
vector<string> t;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(int N, string &S, string &T) {
	// write your code in C++14 (g++ 6.2.0)

	istringstream iss(T);
	string token, token2;
	while (getline(iss, token, ' ')) {
		t.push_back(token);
	}

	for (int i = 0; i < t.size(); i++) {
		int n;
		char c;
		sscanf(t[i].c_str(), "%d%c", &n, &c);
		map[n - 1][c - 'A'] = 1;
	}

	istringstream iss2(S);
	while (getline(iss2, token, ',')) {
		istringstream iss3(token);
		vector<string> s;
		while (getline(iss2, token2, ' ')) {
			s.push_back(token2);
		}

		for (int i = 0; i < s.size(); i++) {
			int n;
			char c;
			sscanf(s[i].c_str(), "%d%c", &n, &c);
			map[n - 1][c - 'A'] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}

	return "";
}

int main() {
	int N = 12;
	string S = "1B 2C,2D 4D";
	string T = "2B 2D 3D 4D 4A";
	cout << solution(N, S, T) << endl;
}