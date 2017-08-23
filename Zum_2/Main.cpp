#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable:4996)

using namespace std;

int solution(vector<int>& A, int S) {
	int n = A.size();
	int pSum[100001] = { 0 , };

	for (int i = 1; i <= n; i++) {
		pSum[i] = pSum[i - 1] + A[i - 1];
	}

	int maxi = 0;
	map<int, int> map1;
	
	for (int i = 0; i <= n; i++) {
		if (map1.count(pSum[i]) > 0) {
			maxi = max(maxi, i - map1[pSum[i]]);
		}
		if (map1.count(pSum[i] + S) == 0) {
			map1[pSum[i] + S] = i;
		}
	}

	return maxi;
}

int main() {
	vector<int> A;
}