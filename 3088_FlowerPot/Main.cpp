#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N;
	
	scanf("%d", &N);

	int** pot = new int*[N];
	for (int i = 0; i < N; ++i)
		pot[i] = new int[3];

	for (int i = 0; i < N; i++) {
		scanf("%d", &pot[i][0]); scanf("%d", &pot[i][1]); scanf("%d", &pot[i][2]);
	}

	int k=0, cnt=1;
	bool flag = false;
	

	for (int i = N - 1; i > 0; i--) {
		flag = false;
		printf("\n%d %d 번째 화분 비교\n", i, i-1);
		for (int j = 0; j < 3; j++) {
			printf("%d %d\n", pot[i][j], pot[i - 1][k]);
			if (pot[i][j] == pot[i - 1][k]) {
				flag = true;
				break;
			}
			if (j == 2) {
				printf("\n");
				k++;
				if (k == 3)
					break;
				j = -1;
			}	
		}
		k = 0;
		if (!flag) {
			cnt++;
		}
	}

	printf("답은 %d\n", cnt);
}