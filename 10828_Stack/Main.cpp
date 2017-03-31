#include <cstdio>
#include <cstring>
#pragma warning(disable: 4996)

using namespace std;

int stack[10000], curser;

void push(int x) {
	stack[++curser] = x;
}

int pop() {
	if (curser == -1)
		return -1;
	return stack[curser--];
}

int size() {
	return curser+1;
}

int empty() {
	if (curser == -1)
		return 1;
	return 0;
}

int top() {
	if (curser == -1)
		return -1;
	return stack[curser];
}

int main() {
	curser = -1;
	int N, num;
	char str[6];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &str);
		if (str[1] == 'u') {
			scanf("%d", &num);
			push(num);
		}
		else if (str[0] == 't')
			printf("%d\n", top());
		else if (str[0] == 's')
			printf("%d\n", size());
		else if (str[0] == 'e')
			printf("%d\n", empty());
		else
			printf("%d\n", pop());
	}
}