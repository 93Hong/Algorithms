#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

bool x[100001], y[100001];

int main() {
	int n = 3, m = 2, cnt = 1;

	vector<int> h;
	vector<int> v;
	bool a = new bool[n + 1];

	for (int i = 0; i < h.size; i++)
		x[h[i]] = true;
	for (int i = 0; i < v.size; i++)
		y[v[i]] = true;

	int row = 1, col = 1;
	int count = 1;

	for (int i = 0; i < n + 1; i++) {
		if (x[i] == true)
			count++;
		else {
			if (row > count)
				row = count;
			count = 1;
		}
	}
	if (row > count)
		row = count;
	count = 1;


	for (int i = 0; i < m + 1; i++) {
		if (y[i] == true)
			count++;
		else {
			if (col > count)
				col = count;
			count = 1;
		}
	}
	if (col > count)
		col = count;

	return col * row;

}
