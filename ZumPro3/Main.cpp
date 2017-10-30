// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <cstdio>
#define INF 1010000000

#pragma warning(disable:4996)

using namespace std;
vector<pair<int, int>> v;


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	for (int i = 0; i < A.size(); i++) {
		v.push_back(make_pair(A[i], B[i]));
	}

	sort(v.begin(), v.end());

	int ans = 0, r = -INF;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > r) {
			ans++;
			r = v[i].second;
		}
		else {
			r = v[i].second;
		}
	}

	return ans;
}

int main() {
	vector<int> A, B;
	A.push_back(1);
	A.push_back(12);
	A.push_back(42);
	A.push_back(70);
	A.push_back(36);
	A.push_back(-4);
	A.push_back(43);
	A.push_back(15);

	B.push_back(5);
	B.push_back(15);
	B.push_back(44);
	B.push_back(72);
	B.push_back(36);
	B.push_back(2);
	B.push_back(69);
	B.push_back(24);

	printf("%d\n", solution(A, B));
}