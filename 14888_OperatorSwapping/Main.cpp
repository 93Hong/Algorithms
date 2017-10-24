#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
#define INF 1100000000

using namespace std;

int arr[11], oper[4];
int maxv = INF, minv = -INF;

int cal() {

}

void solve() {

}

int main() {
	int N, tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d %d %d", &oper[0], &oper[1], &oper[2], &oper[3]);



	printf("%d\n%d\n", maxv, minv);

	return 0;
}
