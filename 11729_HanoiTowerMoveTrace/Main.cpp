#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;


int main() {
	
	int cnt = 0;
	for (int i = 0; i <= 1024; ++i) {
		if ((i & (i - 1)) == 0) {
			++cnt;
		}
	}
	printf("%d\n", cnt);

}