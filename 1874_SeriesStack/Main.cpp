#include <cstring>
#include <cstdio>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;
stack<int> s;
char arr[200001];

int main() {
	int N;
	int num, top = 0, cIndex = 0;
	bool flag = false;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num > top) {
			for (int j = top + 1; j <= num; j++) {
				s.push(j);
				arr[cIndex++] = '+';
			}
			top = num;
			arr[cIndex++] = '-';
			if(!s.empty()) s.pop();
		}
		else {
			if (num != s.top()) {
				flag = true;
				break;
			}
			if(!s.empty())s.pop();
			arr[cIndex++] = '-';
		}
		//top = s.top();
	}

	if (flag) {
		printf("NO\n");
	}
	else {
		for (int i = 0; i < cIndex; i++)
			printf("%c\n", arr[i]);
	}
}