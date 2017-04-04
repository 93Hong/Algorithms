#include <cstdio>
#pragma warning(disable: 4996)

#define M_PI 3.14159265358979323846

using namespace std;

int main() {
	int R;
	scanf("%d", &R);
	R = R*R;
	double a1, a2;

	a1 = M_PI * R;
	a2 = 2 * R;

	printf("%0.6f\n", a1);
	printf("%0.6f\n", a2);
}