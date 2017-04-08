#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int lim[51], box[10000]; //크레인 무게 제한, 박스 무게
int num[51]; //num[x] : 크레인 x개(무게 제한이 큰 순으로x개)로 들 수 있는 무게를 가진 박스의 개수.

bool cmp(int a, int b) { //내림차순 정렬에 사용
	return a > b;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)  //lim[0] = 0 으로 설정됨
		scanf("%d", &lim[i]);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &box[i]);

	sort(lim, lim + n + 1, cmp);
	sort(box, box + m, cmp);
	if (box[0] > lim[0]) { //모든 박스를 못 옮기면 -1 출력, 종료.
		printf("-1\n");
		return 0;
	}

	//num[x] : 크레인 x개(무게 제한이 큰 순으로x개)로 들 수 있는 무게를 가진 박스의 개수.
	int x = 0;
	for (int i = 0; i < m; i++) {
		//크레인의 무게 재한 범위 안에 들면 count
		if (lim[x + 1] < box[i] && box[i] <= lim[x]) {
			num[x + 1]++;
		}
		else {
			x++; i--;
		}
	}

	//최대값 구하기
	int ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += num[i];
		//나눗셈할 때 sum/i 에서 나누어 덜어지지 않는 경우 처리하기 위해서 (sum+(i-1))/i 
		ans = max(ans, (sum + i - 1) / i);
	}

	printf("%d\n", ans);
	return 0;
}