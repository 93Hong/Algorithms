#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

char wd[16];
char re[16];
int L, C;

int cmp(char a, char b) {
	return a < b;
}

void sol(int len, int index, int c1, int c2) {
	if (len < L && index == C - 1) {
		return;
	}
	re[len - 1] = wd[index];
	char c = wd[index];
	bool isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	if (isLowercaseVowel)
		c1++;
	else
		c2++;
	if (L == len) {
		if (c1 > 0 && c2 > 1) {
			for (int i = 0; i < L; i++)
				printf("%c", re[i]);
			printf("\n");
		}
		return;
	}
	for (int i = index + 1; i < C; i++) {
		sol(len + 1, i, c1, c2);
	}
}

int main() {
	char ch;
	scanf("%d", &L); scanf("%d", &C);
	scanf("%c", &ch);
	for (int i = 0; i < C; i++) {
		scanf("%c", &wd[i]);
		if (wd[i] == ' ')
			scanf("%c", &wd[i]);
	}

	sort(wd, wd + C, cmp);

	for (int i = 0; i < C - L + 1; i++)
		sol(1, i, 0, 0);
}