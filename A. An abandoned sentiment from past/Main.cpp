#include <cstdio>
#pragma warning (disable :4996)

using namespace std;

int a[101], b[101];

int main() {
	int n, k, cnt = 0, index;
	scanf("%d", &n); scanf("%d", &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			index = i;

	bool flag = true;

	if (k == 1) {
		a[index] = b[0];
		for (int i = 0; i < n; i++)
			if (a[i] >= a[i + 1]) {
				flag = false;
				break;
			}
		if (flag)
			printf("No");
		else
			printf("Yes");
	}
	else
		printf("Yes");
}