#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#pragma warning(disable:4996)

using namespace std;

vector<pair<string, int>> s;
string st[100002];

int bst(string tmp, int start, int end) {
	int mid = (start + end) / 2;

	if (s[mid].first.compare(tmp) > 0) {
		bst(tmp, start, mid - 1);
	}
	else if (s[mid].first.compare(tmp) < 0) {
		bst(tmp, mid + 1, end);
	}
	else {
		printf("%d\n", s[mid].second);
		return 0;
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		char ch[20];
		scanf("%s", ch);
		s.push_back(make_pair(ch, i));
		st[i] = ch;
	}
	sort(begin(s), end(s));

	for (int i = 0; i < M; i++) {
		char ch[20];
		scanf("%s", ch);
		if (isdigit(ch[0]))
			printf("%s\n", st[stoi(ch)].c_str());
		else {
			bst(ch, 0, N - 1);
		}
	}
}