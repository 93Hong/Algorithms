#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;


bool isInteger(float k) {
	return floor(k) == k;
}

int main() {
	long N;
	scanf("%ld", &N);

	int ans = 0;
	iswdigit(3);
	for (int i = 2; i < 1000001; i++) {
		int a = (i*i - i) / 2;
		double tmp = (N - a) / 2;
		if (isInteger(tmp))
			ans++;
		if (a > N)
			break;
	}

	printf("%d\n", ans);
}