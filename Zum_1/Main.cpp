#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

string solution(int A, int B, int C, int D, int E, int F) {
	vector<int> ve1, ve2;
	string answer = "";

	// 5를 기준으로 2개의 vector에 저장
	A > 5 ? ve2.push_back(A) : ve1.push_back(A);
	B > 5 ? ve2.push_back(B) : ve1.push_back(B);
	C > 5 ? ve2.push_back(C) : ve1.push_back(C);
	D > 5 ? ve2.push_back(D) : ve1.push_back(D);
	E > 5 ? ve2.push_back(E) : ve1.push_back(E);
	F > 5 ? ve2.push_back(F) : ve1.push_back(F);

	// 가장 빠른 시간을 찾는 것이므로 각각 소팅
	sort(ve1.begin(), ve1.end());
	sort(ve2.begin(), ve2.end());

	// 예외처리 (시간으로 표현할 수 없는 경우)
	if (ve2.size() >= 4 || (ve1[0] == 2 && ve1[1] > 3) || ve1[0] > 2) return "NOT POSSIBLE";

	// ve1로만 출력
	if (ve2.size() == 0) {
		answer = to_string(ve1[0]) + to_string(ve1[1]) + ":" + to_string(ve1[2]) + to_string(ve1[3]) + ":" + to_string(ve1[4]) + to_string(ve1[5]);
	}
	// ve2를 ss에
	else if (ve2.size() == 1) {
		answer = to_string(ve1[0]) + to_string(ve1[1]) + ":" + to_string(ve1[2]) + to_string(ve1[3]) + ":" + to_string(ve1[4]) + to_string(ve2[0]);
	}
	// ve2를 mm, ss에
	else if (ve2.size() == 2) {
		answer = to_string(ve1[0]) + to_string(ve1[1]) + ":" + to_string(ve1[2]) + to_string(ve1[3]) + ":" + to_string(ve1[4]) + to_string(ve2[0]);
	}
	// ve2를 hh, mm, ss에
	else {
		answer = to_string(ve1[0]) + to_string(ve2[0]) + ":" + to_string(ve1[1]) + to_string(ve2[1]) + ":" + to_string(ve1[2]) + to_string(ve2[2]);
	}

	return answer;
}

int main() {
	printf("%s\n", solution(6, 6, 6, 6, 6, 6).c_str());
}