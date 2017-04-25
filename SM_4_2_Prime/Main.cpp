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

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

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

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		if (cnt == 0)
			printf("%d\n", 0);
		else
			printf("%d/%d\n", a, b);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}