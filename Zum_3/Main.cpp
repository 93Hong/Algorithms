#include <cstdio>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int solution(vector<int> &A) {
	int ans = -1;
	bool checked = false;
	bool checked2 = false;
	for (int i = 0; i < A.size(); i++) {
		if (i >= 2) {
			if (checked && A[i] >= A[i - 2]) {
				ans = i;
				break;
			}
			if (A[i] > A[i - 2]) {
				if (checked) {
					ans = i;
					break;
				}
			}
			else {
				if (checked2) continue;
				if (checked) {
					if (i - 5 < 0 || A[i - 1] < A[i - 3] - A[i - 5]) {
						checked2 = true;
					}
					else {
						if (A[i] >= A[i - 2] - A[i - 4]) {
							ans = i;
							break;
						}
					}
				}
				else {
					checked = true;
				}
			}
		}
	}

	return ans + 1;
}

int main() {

}