#include <cstdio>
#include <vector>

#pragma warning (disable : 4996)

using namespace std;

int main() {
	int n = 2;
	vector<int> a, b;
	a.push_back(1234);
	a.push_back(4321);
	b.push_back(2345);
	b.push_back(3214);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (a[i] != 0) {
			int a1, b1;
			a1 = a[i] % 10;
			b1 = b[i] % 10;
			if (a1 > b1)
				cnt += a1 - b1;
			else
				cnt += b1 - a1;
			a[i] /= 10;
			b[i] /= 10;
		}
	}
	printf("%d\n", cnt);
}