#include <string>
#include <vector>
using namespace std;

int main() {
	int n = 1;

	for (int i = 10; i > 0; i--) {
		printf("%d\n", (i - n) % 4);
	}
}