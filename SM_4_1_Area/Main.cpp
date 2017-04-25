#include <cstdio>
#include <iostream>
#include <memory>
#include <memory.>
#pragma warning(disable: 4996)

using namespace std;

int map[201][301], map2[201][301], re, cnt, minn = 1100000000, M, N;

void solve(int x, int y, int val) {
	
	if (x < 0 || y < 0 || x >= N || y >= M)
		return;
	if (cnt >= re) {
		if (minn > val)
			minn = val;
		return;
	}
	if (map[x][y] <= val && map2[x][y] != 0) {
		cnt++;
		map2[x][y] = 0;
		solve(x - 1, y, val);
		solve(x, y + 1, val);
		solve(x, y - 1, val);
		solve(x + 1, y, val);
	}
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		
		scanf("%d", &N); scanf("%d", &M);
		re = N * M;
		if (re % 2)
			re = re / 2 + 1;
		else
			re = re / 2;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &map[i][j]);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				memset(map2, -1, sizeof(map2));
				cnt = 0;
				solve(i, j, map[i][j]);
			}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", minn);
		minn = 1100000000;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}