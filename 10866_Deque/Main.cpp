#include <cstdio>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int deque[30001];
int startq = 10000, endq = 10000;

void push_front(int x) {
	deque[--startq] = x;
}

void push_back(int x) {
	deque[++endq] = x;
}

int pop_front() {
	int x = deque[startq++];
	return x;
}

int pop_back() {
	int x = deque[endq--];
	return x;
}

int size() {
	return endq - startq;
}

int empty() {
	if (size())
		return 0;
	return 1;
}

int front() {
	if (empty())
		return -1;
	return deque[startq];
}

int back() {
	if (empty())
		return -1;
	return deque[endq];
}

int main() {
	int N;
	scanf("%d", &N);

	while (N--) {
		string s;
		scanf("%s", s);

		if (s.compare("push_back")) {
			int x;
			scanf("%d", &x);
			push_back(x);
		}
		else if (s.compare("push_front")) {
			int x;
			scanf("%d", &x);
			push_front(x);
		}
		else if (s.compare("front")) {
			printf("%d\n", front());
		}
		else if (s.compare("back")) {
			printf("%d\n", back());
		}
		else if (s.compare("size")) {
			printf("%d\n", size());
		}
		else if (s.compare("pop_back")) {
			printf("%d\n", pop_back());
		}
		else if (s.compare("pop_front")) {
			printf("%d\n", pop_front());
		}
		else { // empty
			printf("%d\n", empty());
		}
	}
}