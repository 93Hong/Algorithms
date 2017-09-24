#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
vector<int> vec;


int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	int maxV = vec[0];

	for (int i = 1; i < vec.size(); i++) {
		if (maxV < (i + 1) * min(vec[i - 1], vec[i])) {
			maxV = (i + 1) * min(vec[i - 1], vec[i]);
		}
	}

	printf("%d\n", maxV);
}