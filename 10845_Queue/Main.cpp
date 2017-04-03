#include <cstdio>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	char input[6];
	int queue[10001], val, first = 0, last = 0;

	while (N--) {
		scanf("%s", input);
		if (input[1] == 'u') {
			scanf("%d", &val);
			queue[last++] = val;
		}
		else if (input[1] == 'o') {
			if (last == first)
				printf("-1\n");
			else {
				printf("%d\n", queue[first++]);
			}			
		}
		else if (input[1] == 'i') {
			printf("%d\n", last - first);
		}
		else if (input[1] == 'm') {
			if (last == first)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (input[1] == 'r') {
			if (last == first)
				printf("-1\n");
			else
				printf("%d\n", queue[first]);
		}
		else if (input[1] == 'a') {
			if (last == first)
				printf("-1\n");
			else
				printf("%d\n", queue[last-1]);
		}
	}
}