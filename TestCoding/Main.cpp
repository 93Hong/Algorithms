#include <iostream>
using namespace std;
long long d[31];
int main() {
	int n;
	cin >> n;
	d[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		d[i] = d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
	}
	cout << d[n] << '\n';
	return 0;
}
