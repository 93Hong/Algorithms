#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#pragma warning(disable:4996)

using namespace std;

set<string> s;
vector<string> v;

int main() {
	int N, M;
	string str;

	scanf("%d %d", &N, &M);

	while (N--) {
		cin >> str;
		s.insert(str);
	}

	while (M--) {
		cin >> str;
		if (s.find(str) != s.end()) {
			v.push_back(str);
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%s\n", v[i].c_str());
}