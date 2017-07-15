#include <cstdio>
#include <map>
#pragma warning (disable:4996)

using namespace std;


void countDuplication(int arr[], int size) {
	map<int, int> cntMap;
	for (int i = 0; i < size; i++)
		cntMap[arr[i]] = cntMap[arr[i]] + 1;
}

int main() {
	int arr[] = { 0, 1, 2, 3, 3, 3, 4, 0 };
	countDuplication(arr, 8);
}