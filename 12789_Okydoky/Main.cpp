#include <cstdio>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;
stack<int> st;

int main() {
	int N, num, cnt = 1;
	int line[1001];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		line[i] = num;
	}
	int i;
	for (i = 0; i < N; i++) {
		if (line[i] != cnt) {
			if (st.empty())
				st.push(line[i]);
			else if (st.top() < line[i])
				break;
		}
		else
			cnt++;
	}

	bool flag = true;

	for (i; i < N - 1; i++) {
		if (line[i] > line[i + 1]) {
			flag = false;
			break;
		}
	}

	if (flag)
		printf("Nice\n");
	else
		printf("Sad\n");
}