#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

char map[20][20];

int main() {
	char c;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			scanf("%1c", &map[i][j]);
		}
		scanf("%c", &c);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			if (map[i][j] == 'x') {
				for (int k = i; k > 0; k--) {
					map[k][j] = map[k - 1][j];
				}
				map[0][j] = '.';
				printf("\n");
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 1; j++) {
						printf("%c", map[i][j]);
					}
					printf("\n");
				}
			}
			
		}
	}
}