#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int getN(char s) {
	if (s[0] == '*' || s[0] == '/')
		return 2;
	return 1;
}

int main() {
	string s;
	cin >> s;

	stack<string> st;

	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]))
			printf("%c", s[i]);
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			if (st.empty()) {
				st.push(string(1, s[i]));
			}
			else {
				while ((getN(st.top().c_str()[0]) >= getN(s[i]))) {
					printf("%s", st.top().c_str());
					st.pop();
				}
			}
		}
		else if (s[i] == ')') {
			string c[3];
			int cur = 0;
			while (st.top().compare("(") != 0) {
				c[cur++] = st.top();
				st.pop();
			}
			st.pop();
			string tmp = c[2] + c[0] + c[1];
			st.push(tmp.c_str());
		}
		else {
			st.push(string(1, s[i]));
		}
	}

	printf("%s\n", st.top().c_str());
}