#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;

string ward;
stack<char> one, two;

int main() {
	int N, num;
	char c;
	cin >> ward;

	scanf("%d", &N);
	for (int i = 0; i < ward.length(); i++)
		one.push(ward.at(i));

	while (N--) {
		scanf("%c", &c);
		if (c == '\n')
			scanf("%c", &c);
		if (c == 'L' && !one.empty()) {
			char ch = one.top();
			two.push(ch);
			one.pop();
		}
		else if (c == 'D' && !two.empty()) {
			char ch = two.top();
			one.push(ch);
			two.pop();
		}
		else if (c == 'B' && !one.empty()) {
			one.pop();
		}
		else if (c == 'P') {
			scanf("%c", &c);
			scanf("%c", &c);
			one.push(c);
		}
	}
	while (!one.empty()) {
		two.push(one.top());
		one.pop();
	}
	while (!two.empty()) {
		printf("%c", two.top());
		two.pop();
	}
}
