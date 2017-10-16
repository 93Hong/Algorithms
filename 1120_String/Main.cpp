#include <cstdio>
#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	string s1, s2;

	cin >> s1;
	cin >> s2;
	int ans = 51;

	for (int i = 0; i < s2.length() - s1.length() + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < s1.length(); j++) {
			if (s2[i + j] != s1[j])
				cnt++;
		}
		if (ans > cnt) {
			ans = cnt;
		}
	}

	printf("%d\n", ans);
}