#include <cstdio>
#include <deque>
#pragma warning(disable:4996)

using namespace std;

deque<int> dq;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	while (dq.size() > 1) {
		printf("%d ", dq.front());
		dq.pop_front();
		int tmp = dq.front();
		dq.pop_front();
		dq.push_back(tmp);
	}
	printf("%d", dq.front());
}