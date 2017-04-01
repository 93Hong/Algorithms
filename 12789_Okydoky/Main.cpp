#include <cstdio>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;
stack<int> st;

int main() {
	int N, num, cnt = 1;
	int line[3000], line2[3000];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		line[i] = num;
		line2[i] = 1001;
	}
	int i, j = 1;
	bool flag = true;

	for (i = 0; i < N; i++) {
		if (line[i] == cnt) {
			cnt++;
		}
		else if (line2[j-1] == cnt) {
			cnt++;
			j--;
			i--;
		}
		else {
			line2[j] = line[i];
			if (line2[j] > line2[j - 1]) {
				printf("Sad\n");
				flag = false;
				break;
			}
			j++;
		}
	}
	if (flag)
		printf("Nice\n");
}