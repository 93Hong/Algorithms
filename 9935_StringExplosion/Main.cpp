#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string s, t;
	stack<char> st;
	
	cin >> s;
	cin >> t;

	int s_size = s.length(), t_size = t.length(), st_size;
	char t_last = t[t_size - 1];

	for (int i = 0; i < s_size; i++) {
		char c = s[i];
		st.push(c);

		if (c == t_last && st.size() >= t_size) {
			int cnt = 1;
			bool nots = false;
			stack<char> check;

			for (int j = t_size - 1; j >= 0; j--) {
				if (t[j] != st.top()) {
					nots = true;
					break;
				}
				check.push(st.top());
				st.pop();
			}
			while (!check.empty() && nots == true) {
				st.push(check.top());
				check.pop();
			}
		}
	}

	if (st.empty())
		printf("FRULA\n");
	else {
		string a;
		while (!st.empty()) {
			a += st.top();
			st.pop();
		}
		reverse(a.begin(), a.end());
		cout << a << endl;
	}

}