#include <cstdio>
#include <set>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int main() {
	vector<int> T;
	T.push_back(3);
	T.push_back(4);
	T.push_back(7);
	T.push_back(7);
	T.push_back(6);
	T.push_back(6);
	
	set<int> s;
	int cnt = 0;
	for (int i = 0; i < T.size(); i++) {
		if (s.find(T[i]) == s.end()) {
			s.insert(T[i]);
			cnt++;
		}
	}

	printf("%d\n", cnt);
	int halfNumOfCandy = T.size() / 2;

	if (cnt > halfNumOfCandy) {
		printf("%d\n", halfNumOfCandy);
	}
	printf("%d\n", cnt);
}