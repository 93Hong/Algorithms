#include <cstdio>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int check[26];

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int len;
		char s[100001], d[100001];
		scanf("%d", &len);
		scanf("%s", s);

		memset(check, 0, sizeof(check));

		for (int i = 0; i < len; i++) {
			check[s[i] - 97]++;
		}

		for (int i = len - 1; i >= 0; i--) {
			d[i] = s[i] + check[s[i] - 97] - 1;
			check[s[i] - 97]--;
		}
		
		for (int i = 0; i < len; i++) {
			printf("%c", d[i]);
		}
	}
}