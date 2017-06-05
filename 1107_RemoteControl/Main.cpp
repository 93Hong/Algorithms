#include <cstdio>
#include <math.h>
#pragma warning(disable: 4996)

bool broken[10];

int isPossible(int chenel) {
	if (chenel == 0)
		if (broken[chenel])
			return 0;
		else
			return 1;
	int len = 0;
	while (chenel > 0) {
		if (broken[chenel % 10])
			return 0;
		len++;
		chenel /= 10;
	}
	return len;
}

int main() {
	int N, M, button;
	int initial = 100;
	
	scanf("%d", &N); scanf("%d", &M);

	int ans = N - initial;
	if (ans < 0)
		ans = -ans;

	while (M--) {
		scanf("%d", &button);
		broken[button] = true;
	}

	for (int i = 0; i <= 1000000; i++) {
		
		int len = isPossible(i);
		
		if (len != 0) {
			int press = N - i;
			if (press < 0)
				press = i - N;
			if (ans > len + press)
				ans = len + press;
		}
	}

	printf("%d\n", ans);
	return 0;
}