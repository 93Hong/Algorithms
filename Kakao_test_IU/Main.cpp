#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int val = 0, cnt = 1;

	while (1) {
		val = pow(3, cnt) + cnt * 2;
		if (n < val)
			break;
		cnt++;
		printf("%d %d\n", val, cnt);
	}
	cnt--;

	vector<char> s;
	for (int i = 0; i < cnt * 3; i++) {
		if (i < cnt)
			s.push_back('*');
		else
			s.push_back('+');
	}

	

	do {
		int value = 1;
		for (int i = 0; i < s.size(); i++) {

		}

	} while (next_permutation(s.begin(), s.end()));
}