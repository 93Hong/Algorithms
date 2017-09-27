#include <cstdio>
#include <string>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int arr[26][1];

int main() {
	string s, ans;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (islower(s[i]) > 0) {
			arr[s[i] - 'a'][0]++;
		}
	}
	
	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i][0]);

	for (int i = 0; i < s.length(); i++) {
		if (islower(s[i]) > 0) {
			int alparCnt = arr[s[i] - 'a'][0];
			
		}
	}
}