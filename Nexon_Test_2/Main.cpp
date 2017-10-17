#include <cstdio>
#include <string>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string s = "juliasamanthasamanthajulia";
	string x = "ant";

	stack<char> st;
	int s_size = s.length(), x_size = x.length(), st_size, ans;
	char x_last = x[x_size - 1];

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		st.push(c);

		if (c == x_last && st.size() >= x_size) {
			bool nots = false;
			stack<char> check;

			for (int j = x_size - 1; j >= 0; j--) {
				if (x[j] != st.top() && x[j] != '*') {
					nots = true;
					break;
				}
				check.push(st.top());
				st.pop();
			}

			if (nots == false) {
				ans = i - x_size + 1;
				break;
			}

			while (!check.empty() && nots == true) {
				st.push(check.top());
				check.pop();
			}
		}
	}

	printf("%d\n", ans);
}