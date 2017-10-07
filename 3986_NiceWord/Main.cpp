#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int N, ans = 0;
	scanf("%d", &N);

	while (N--) {
		string str;
		stack<char> s;

		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (!s.empty() && s.top() == str[i]) {
				s.pop();
			}
			else
				s.push(str[i]);
		}

		if (s.empty())
			ans++;
	}

	printf("%d\n", ans);
}