#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	while (N--) {
		string s;
		cin >> s;
		stack<char> left, right;

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];

			if (c == '<') {
				if (!left.empty()) {
					right.push(left.top());
					left.pop();
				}
			}
			else if (c == '>') {
				if (!right.empty()) {
					left.push(right.top());
					right.pop();
				}
			}
			else if (c == '-') {
				if (!left.empty()) {
					left.pop();
				}
			}
			else {
				left.push(c);
			}
		}

		while (!right.empty()) {
			left.push(right.top());
			right.pop();
		}

		string printing;
		while (!left.empty()) {
			printing += left.top();
			left.pop();
		}
		reverse(printing.begin(), printing.end());
		cout << printing << endl;
	}
}