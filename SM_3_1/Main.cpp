#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int M, N, re;
	scanf("%d", &M); scanf("%d", &N);

	if (M % 2 == 0 && N % 2 == 0)
		re = M*N / 2 - 2;
	else
		re = M*N / 2 - 1;
	
	printf("%d\n", re);
}