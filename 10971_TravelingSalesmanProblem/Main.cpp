#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable: 4996)

using namespace std;

int W[11][11];
vector<int> v;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		v.push_back(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &W[i][j]);
	}
	int result = 100000000;

	do {
		int sum = 0;
		bool flag = true;
		for (int i = 0; i < N-1; i++) {
			if (W[v.at(i)][v.at(i+1)] == 0) {
				//sum = 0;
				flag = false;
				//break;
			}
			else
				sum += W[v.at(i)][v.at(i + 1)];
		}
		if (flag && W[v.at(N - 1)][v.at(0)] != 0) {
			sum += W[v.at(N-1)][v.at(0)];
			if (result > sum)
				result = sum;
		}
		

	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", result);
	return 0;
}