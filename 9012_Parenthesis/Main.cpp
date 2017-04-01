#include <cstring>
#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	for (int j = 0; j < N; j++) {
		stack<char> s;
		string str;
		cin >> str;
		bool flag = true;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else {
				if (s.empty()) {
					flag = false;
					break;
				}
				s.pop();
			}
		}
		if (flag && !s.empty())
			flag = false;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}