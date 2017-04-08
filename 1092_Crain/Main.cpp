#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int lim[51], box[10000]; //ũ���� ���� ����, �ڽ� ����
int num[51]; //num[x] : ũ���� x��(���� ������ ū ������x��)�� �� �� �ִ� ���Ը� ���� �ڽ��� ����.

bool cmp(int a, int b) { //�������� ���Ŀ� ���
	return a > b;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)  //lim[0] = 0 ���� ������
		scanf("%d", &lim[i]);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &box[i]);

	sort(lim, lim + n + 1, cmp);
	sort(box, box + m, cmp);
	if (box[0] > lim[0]) { //��� �ڽ��� �� �ű�� -1 ���, ����.
		printf("-1\n");
		return 0;
	}

	//num[x] : ũ���� x��(���� ������ ū ������x��)�� �� �� �ִ� ���Ը� ���� �ڽ��� ����.
	int x = 0;
	for (int i = 0; i < m; i++) {
		//ũ������ ���� ���� ���� �ȿ� ��� count
		if (lim[x + 1] < box[i] && box[i] <= lim[x]) {
			num[x + 1]++;
		}
		else {
			x++; i--;
		}
	}

	//�ִ밪 ���ϱ�
	int ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += num[i];
		//�������� �� sum/i ���� ������ �������� �ʴ� ��� ó���ϱ� ���ؼ� (sum+(i-1))/i 
		ans = max(ans, (sum + i - 1) / i);
	}

	printf("%d\n", ans);
	return 0;
}