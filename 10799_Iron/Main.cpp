#include <iostream>
#include <string>
#pragma warning(disable: 4996)

using namespace std;
int re[100100];
string str;

int main() {
	int n, index = -1, result = 0;
	char pre = 'a';
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '(') {
			index++;
			pre = '(';
		}
		else if (pre == '(' && str.at(i) == ')') {
			index--;
			pre = ')';
			for (int j = 0; j < index + 1; j++)
				re[j]++;
		}
		else if (str.at(i) == ')') {
			pre = ')';
			result += re[index] + 1;
			re[index--] = 0;
		}
	}

	printf("%d\n", result);
}