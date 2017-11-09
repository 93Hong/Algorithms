#include <cstdio>
#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string s;
	cin >> s;

	int numOfCloseBrath = 0, numOfOpenBrath = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')')
			numOfCloseBrath++;
	}

	int i;

	for (i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			numOfOpenBrath++;
		else if (s[i] == ')')
			numOfCloseBrath--;
		if (numOfCloseBrath == numOfOpenBrath)
			break;
	}

	printf("%d\n", i + 1);
}