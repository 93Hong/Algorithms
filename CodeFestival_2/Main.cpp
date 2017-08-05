#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int MOD = 20170805;
int M, N;
int d[501][501][3];
vector<vector<int>> city;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int go(int i, int j, int pre) {

	if (i == M - 1 && j == N - 1)return 1;
	if (i >= M || j >= N) return 0;


	int &ans = d[i][j][pre];
	if (ans != -1)return ans;

	ans = 0;

	if (city[i][j] == 0) {
		ans += go(i + 1, j, 1);
		ans %= MOD;
		ans += go(i, j + 1, 2);
	}
	else if (city[i][j] == 2) {
		if (pre == 1) ans += go(i + 1, j, 1);
		else ans += go(i, j + 1, 2);
	}

	return ans%MOD;
}

int solution(int m, int n, vector<vector<int>> city_map) {
	M = m;
	N = n;
	city = city_map;
	memset(d, -1, sizeof(d));
	int answer = 0;

	answer = go(0, 0, 0);

	return answer;
}