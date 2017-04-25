#include <cstdio>
#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

int arr[100001];

bool isPrime(int number) {

	if (number < 2) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false;
	for (int i = 3; (i*i) <= number; i += 2) {
		if (number % i == 0) return false;
	}
	return true;

}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

		int N, num, cnt = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			if (isPrime(num))
				cnt++;
		}
		int a = cnt, b = N;

		num = gcd(cnt, N);
		if (num != 1) {
			a = cnt / num;
			b = N / num;
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		if (cnt == 0)
			printf("%d\n", 0);
		else
			printf("%d/%d\n", a, b);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}