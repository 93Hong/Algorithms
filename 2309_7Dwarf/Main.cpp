#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int height[9], result[7];
int val = 100, dwarf = 7, index;
bool check;

bool cmp(int a, int b) {
	return a < b;
}

void dwarfs() {
	int sum = 0;
	for (int i = 0; i < dwarf; i++)
		sum += height[i];

	if (sum == val) {
		for (int i = 0; i < dwarf; i++)
			result[i] = height[i];
		return;
	}
	else {
		for (int i = 0; i < dwarf; i++) {
			if (sum - height[i] + height[dwarf] == val) {
				result[dwarf - 1] = height[dwarf];
				check = true;
			}
			else if (sum - height[i] + height[dwarf + 1] == val) {
				result[dwarf - 1] = height[dwarf + 1];
				check = true;
			}
			if (check) {
				int k = 0;
				for (int j = 0; j < dwarf; j++)
					if (j != i)
						result[k++] = height[j];
				return;
			}
		}
		result[dwarf - 2] = height[dwarf];
		result[dwarf - 1] = height[dwarf + 1];
		val -= (height[dwarf] + height[dwarf + 1]);
		dwarf -= 2;
		dwarfs();
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		scanf("%d", &height[i]);

	sort(height, height + 9, cmp);

	dwarfs();

	for (int i = 0; i < 7; i++)
		printf("%d\n", result[i]);
}