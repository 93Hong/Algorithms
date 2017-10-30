#include <cstdio>
#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int arr[10];

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d", i);
		}
	}
}