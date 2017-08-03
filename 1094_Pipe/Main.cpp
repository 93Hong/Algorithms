#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int X, ans = 0;
	scanf("%d", &X);

	
	while ((X >> 1)) {
		if (X & 1)
			ans++;
		X = X >> 1;
	}
	if (X & 1)
		ans++;

	printf("%d\n", ans);
}