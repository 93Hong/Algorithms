#include <cstdio>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

stack<int> s;
int arr[1000001];

int main() {
	int N, X;
	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int minst = 1000000, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (s.size() < X) {
			s.push(arr[i]);
			if (minst > arr[i])
				minst = arr[i];
		}
		else {

			minst = 1000000;
		}
	}
}