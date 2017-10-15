#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)

using namespace std;
queue<int> q;
vector<int> v;

int main() {
	int n, num = 2;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (b == 1) {
			q.push(a);
		}
		else {
			int size = q.size();
			for (int j = 0; j < size; j++) {
				int tmp = q.front();
				q.pop();
				if (tmp != a)
					q.push(tmp);
			}
		}
	}

	while (num--) {
		v.push_back(q.front());
		q.pop();
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++)
		printf("%d", v[i]);
}