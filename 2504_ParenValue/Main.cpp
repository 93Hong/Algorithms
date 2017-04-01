#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;
stack<char> st;

int main() {
	string str;
	cin >> str;

	char c[35], a;
	int cIndex = 0, val = 1, re = 0;
	bool flag = false;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			if (st.top() != '(') {
				cIndex = -1;
				break;
			}
			st.pop();
		}
		else if (str[i] == ']') {
			if (st.top() != '[') {
				cIndex = -1;
				break;
			}
			st.pop();
		}
	}
	if (cIndex == -1 || !st.empty()) {
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			flag = true;
			val *= 2;
		}
		else if (str[i] == '[') {
			flag = true;
			val *= 3;
		}
		else if (str[i] == ')') {
			if (flag)
				re += val;
			val /= 2;
			flag = false;
		}
		else if (str[i] == ']') {
			if (flag)
				re += val;
			val /= 3;
			flag = false;
		}
	}
	printf("%d\n", re);
}