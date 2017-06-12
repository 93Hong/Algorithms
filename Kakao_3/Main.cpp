#include <cstdio>
#include <string>
#include <stack>
#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

stack<int> st;
vector<int> output(26,0);

int main() {
	string s = "1(3232)23(3)";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '#') {
			int tmp = st.top();
			st.pop();
			tmp += st.top() * 10;
			st.pop();
			st.push(tmp);
		}
		else if (s[i] == '(') {
			int tmp = st.top();
			int value = 0;
			while (s[i+1] != ')') {
				i++;
				if (value != 0)
					value *= 10;
				value += s[i] - '0';
			}

			for (int j = 1; j < value; j++)
				st.push(tmp);
			i++;
		}
		else
			st.push(s[i] - '0');
	}
	

	while (!st.empty()) {
		output[st.top() - 1]++;
		st.pop();
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", output[i]);
}