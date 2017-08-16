#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int num[100001][3], minD[100001][3];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i][0]);
		scanf("%d", &num[i][1]);
		scanf("%d", &num[i][2]);
	}

	minD[0][0] = num[0][0]; 
	minD[0][1] = num[0][1]; 
	minD[0][2] = num[0][2];

	for (int i = 1; i < N; i++) {
		minD[i][0] = num[i][0] + max(minD[i - 1][0], minD[i - 1][1]);
		minD[i][1] = num[i][1] + max(minD[i - 1][0], max(minD[i - 1][1], minD[i - 1][2]));
		minD[i][2] = num[i][2] + max(minD[i - 1][2], minD[i - 1][1]);
	}

	printf("%d\n", max(minD[N - 1][0], max(minD[N - 1][1], minD[N - 1][2])));

	for (int i = 1; i < N; i++) {
		minD[i][0] = num[i][0] + min(minD[i-1][0], minD[i - 1][1]);
		minD[i][1] = num[i][1] + min(minD[i - 1][0], min(minD[i - 1][1], minD[i - 1][2]));
		minD[i][2] = num[i][2] + min(minD[i - 1][2], minD[i - 1][1]);
	}

	
	printf("%d\n", min(minD[N - 1][0], min(minD[N - 1][1], minD[N - 1][2])));
}