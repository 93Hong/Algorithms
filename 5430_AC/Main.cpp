#include <cstdio>
#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		char p[100001];
		int n, arr[100001];

		scanf("%s", p);
		scanf("%d", &n);

		getchar(); getchar();
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			getchar();
		}

		int s = 0, e = n - 1;
		bool flag = true, isErr = false;
		int len = strlen(p);

		for (int i = 0; i < len; i++) {
			if (p[i] == 'R') {
				flag = !flag;
			}
			if (p[i] == 'D') {
				if (flag) {
					s++;
					if (s >= n) {
						printf("error\n");
						isErr = true;
						break;
					}
				}
				else {
					e--;
					if (e < s) {
						printf("error\n");
						isErr = true;
						break;
					}
				}
			}
		}

		if (!isErr) {
			if (flag) {
				printf("[");
				for (int i = s; i < e; i++)
					printf("%d,", arr[i]);
				printf("%d]\n", arr[e]);
			}
			else {
				printf("[");
				for (int i = e; i > s; i--)
					printf("%d,", arr[i]);
				printf("%d]\n", arr[s]);
			}
		}
	}
}