#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main() {
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ans[1000], depth = 0;
		stack<char> stk, q;
		string str;
		cin >> str;
		int len = (int)str.length();
		//»Æ¿Œ
		bool found = true;
		int length = 0;

		char cr[1000];
		for (int j = 0; j < len; j++) {
			char c = str[j];
			if (c == '{' || c == '(' || c == '[' || c == ')' || c == '}' || c == ']') {
				q.push(c);
				cr[length] = c;
				length++;
			}
		}

		for (int j = 0; j < len && found; j++) {
			switch (str[j]) {
			case '{':
				stk.push('{');
				break;
			case '(':
				stk.push('(');
				break;
			case '[':
				stk.push('[');
				break;
			case '}':
				if (!stk.empty() && stk.top() == '{') stk.pop();
				else found = false;
				break;
			case ')':
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else found = false;
				break;
			case ']':
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else found = false;
			default:
				break;
			}
		}

		if (!stk.empty() || !found) {
			int index = length;
			bool checked = true;
			while (!q.empty()) {
				if (q.top() == ')' || q.top() == '}' || q.top() == ']') {
					index--;
					checked = false;
					break;
				}
				q.pop();
			}
			if (checked)
				printf("-1\n");
			else
				printf("%d\n", index);
		}
		else {
			int a = 0;
			for (int i = 0; i < length; i++) {
				if (cr[i] == '(' || cr[i] == '{' || cr[i] == '[') {
					q.push(cr[i]);
					ans[i] = depth;
					depth++;
				}
				else {
					q.pop();
					ans[i] = --depth;
				}
			}

			for (int i = 0; i < length; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
	}
}