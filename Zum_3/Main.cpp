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
				if (checked) { //이미 안쪽으로 들어온 후
					ans = i;
					break;
				}
			}
			else { //A[i] <= A[i - 2]
				if (checked2) continue;
				if (checked) { //이미 안쪽으로 들어온 경우
							   //일단 로직짜보고 i 음수범위 체크 해주기 
					if (i - 5 < 0 || A[i - 1] < A[i - 3] - A[i - 5]) {
						checked2 = true; //완전히 안쪽으로 들어옴   
					}
					else {
						if (A[i] >= A[i - 2] - A[i - 4]) {
							ans = i;
							break;
						}
					}
				}
				else { //처음 안쪽으로 들어온 경우
					checked = true;
				}
			}
		}
	}

	return ans + 1;
}

int main() {

}