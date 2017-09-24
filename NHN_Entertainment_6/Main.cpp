#include <cstdio>
#pragma warning(disable : 4996)

using namespace std;

int main() {
	float a = 1, b = 1, c = 1;

	float ans = 0;
	//ans = b*++c;

	c = c + 1; a = b * c;
	printf("%f\n", ans);
	printf("%f\n", a);
}