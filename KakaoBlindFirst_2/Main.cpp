#include <string>

using namespace std;
int arr[4];

int solution(string dartResult) {
	int answer = 0;

	int cursor = 0;
	bool isPlus = true;

	for (int i = 0; i < dartResult.length(); i++) {

		if (dartResult[i] <= 57 && dartResult[i] >= 48) {
			if (isPlus) {
				cursor++;
				isPlus = false;
			}
			arr[cursor] = arr[cursor] * 10 + (int)(dartResult[i] - 48);
		}

		else {
			isPlus = true;

			if (dartResult[i] == '*') {
				arr[cursor] *= 2;
				if (cursor != 1) {
					arr[cursor - 1] *= 2;
				}
			}
			else if (dartResult[i] == '#')
				arr[cursor] = (-1) * arr[cursor];

			else if (dartResult[i] == 'S')
				continue;
			else if (dartResult[i] == 'D')
				arr[cursor] = arr[cursor] * arr[cursor];
			else if (dartResult[i] == 'T')
				arr[cursor] = arr[cursor] * arr[cursor] * arr[cursor];
			
		}
	}

	answer = arr[1] + arr[2] + arr[3];
	return answer;
}