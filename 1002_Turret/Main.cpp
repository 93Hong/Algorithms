#include <cstdio>
#include <math.h>
#pragma warning(disable: 4996)
using namespace std;

int main() {
	int T;
	int x1, y1, r1, x2, y2, r2, dis2, re = 0, bigR, sR;
	
	scanf("%d",&T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &x1); scanf("%d", &y1); scanf("%d", &r1); scanf("%d", &x2); scanf("%d", &y2); scanf("%d", &r2);
		double dis = sqrt((x2 - x1) * (x2 - x1) + (y1 - y2) * (y1 - y2));
		
		if (r1 > r2) {
			bigR = r1;
			sR = r2;
		}
		else {
			bigR = r2;
			sR = r1;
		}
		
		if (x1 == x2 && y1 == y2 && r1 == r2)
			re = -1;
		else if (bigR == sR + dis)
			re = 1;
		else if (bigR > sR + dis)
			re = 0;
		else {
			if (dis == r1 + r2)
				re = 1;
			else if (dis > r1 + r2)
				re = 0;
			else
				re = 2;
		}

		printf("%d\n", re);
	}
	return 0;
}