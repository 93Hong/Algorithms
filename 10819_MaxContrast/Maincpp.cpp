#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#pragma warning(disable: 4996)

using namespace std;
vector<int> v;
int result = 0;

void maxContrast() {
	int tmp = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		tmp += abs(v.at(i) - v.at(i + 1));
	}
	if (result < tmp)
		result = tmp;
}

int main() {
	int N;
	
	scanf("%d", &N);

	while (N--) {
		int n;
		scanf("%d", &n);
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	do {
		maxContrast();
	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", result);
	return 0;
}