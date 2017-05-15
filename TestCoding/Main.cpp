#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> strs;
string t, s;

int answer = 0, min = 30000;

void solve(vector<string> strs, string s1, int cnt) {
	if (s1.length() == 0) {
		if (min > cnt)
			min = cnt;
		return;
	}

	for (int i = 0; i < strs.size(); i++) {
		if (s1.find(strs.at(i)) == 0) {
			string s2 = s1.substr(strs.at(i).length());
			solve(strs, s2, cnt + 1);
		}
	}
}

int main() {
	s = "banana";
	strs.push_back("ba");
	strs.push_back("an");

	
	solve(strs, s, 0);
	
	if (min == 30000)
		answer = -1;
	else
		answer = min;

	printf("%d\n", answer);
}
/*
for (int i = 0; i < strs.size(); i++) {
if (s.find(strs.at(i)) == -1)
answer = -1;
}*/