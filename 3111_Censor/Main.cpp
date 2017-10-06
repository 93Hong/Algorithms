#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

stack<char> s, e;

int main() {
	string A, T;
	cin >> A;
	cin >> T;

	int r = 0, l = T.size() - 1;
	bool flag = true;
	int wordSize = A.size();

	while (r <= l) {
		stack<char> del;
		if (flag) {
			s.push(T[r++]);
			if (s.top() == A[wordSize - 1] && s.size() >= wordSize) {
				for (int i = wordSize - 1; i >= 0; i--) {
					if (s.top() != A[i])
						break;
					del.push(s.top());
					s.pop();
				}
				if (del.size() != wordSize && !del.empty())
					while (!del.empty()) {
						s.push(del.top());
						del.pop();
					}
				else
					flag = false;
			}
		}
		else {
			e.push(T[l--]);
			if (e.top() == A[0] && e.size() >= wordSize) {
				for (int i = 0; i < wordSize; i++) {
					if (e.top() != A[i])
						break;
					del.push(e.top());
					e.pop();
				}
				if (del.size() != wordSize && !del.empty())
					while (!del.empty()) {
						e.push(del.top());
						del.pop();
					}
				else
					flag = true;
			}
		}
	}

	if (flag) {
		while (!e.empty()) {
			stack<char> del;
			s.push(e.top());
			e.pop();
			if (s.top() == A[wordSize - 1] && s.size() >= wordSize) {
				for (int i = wordSize - 1; i >= 0; i--) {
					if (s.top() != A[i])
						break;
					del.push(s.top());
					s.pop();
				}
				if (del.size() != wordSize && !del.empty())
					while (!del.empty()) {
						s.push(del.top());
						del.pop();
					}
			}
		}
		while (!s.empty()) {
			printf("%c", s.top());
			s.pop();
		}
	}
	else if (!flag) {
		while (!s.empty()) {
			stack<char> del;
			e.push(s.top());
			s.pop();
			if (e.top() == A[0] && e.size() >= wordSize) {
				for (int i = 0; i < wordSize; i++) {
					if (e.top() != A[i])
						break;
					del.push(e.top());
					e.pop();
				}
				if (del.size() != wordSize && !del.empty())
					while (!del.empty()) {
						e.push(del.top());
						del.pop();
					}
			}
		}
		queue<char> q;
		while (!e.empty()) {
			q.push(e.top());
			e.pop();
		}
		while (!q.empty()) {
			printf("%c", q.front());
			q.pop();
		}
	}

}