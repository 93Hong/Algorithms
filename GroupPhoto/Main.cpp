#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int getposition(const char *array, size_t size, char c) {
	const char* end = array + size;
	const char* match = std::find(array, end, c);
	return (end == match) ? -1 : (match - array);
}

int main() {
	char arr[8] = { 'A', 'C', 'F' , 'J' , 'M' , 'N' , 'R' , 'T' };
	int ans = 0;
	int size = sizeof(arr) / sizeof(char);

	int N = 2;
	vector<string> data;

	data.push_back("R~T>2");
	data.push_back("N~F=0");

	int cnt = 0;

	do {
		bool ok = true;
		for (int i = 0; i < N; i++) {
			int x = getposition(arr, size, data[i][0]);
			int y = getposition(arr, size, data[i][2]);

			if (data[i][3] == '<') {
				if (abs(x - y) - 1 >= data[i][4] - '0')
					ok = false;
			}
			else if (data[i][3] == '>') {
				if (abs(x - y) - 1 <= data[i][4] - '0')
					ok = false;
			}
			else {
				if (abs(x - y) - 1 != data[i][4] - '0')
					ok = false;
			}
		}
		if (ok)
			ans++;
		
	} while (next_permutation(arr, arr + size));

	printf("%d\n", ans);
}