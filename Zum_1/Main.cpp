#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

string solution(int A, int B, int C, int D, int E, int F) {
	vector<int> ve1, ve2;
	string answer = "";

	// 5�� �������� 2���� vector�� ����
	A > 5 ? ve2.push_back(A) : ve1.push_back(A);
	B > 5 ? ve2.push_back(B) : ve1.push_back(B);
	C > 5 ? ve2.push_back(C) : ve1.push_back(C);
	D > 5 ? ve2.push_back(D) : ve1.push_back(D);
	E > 5 ? ve2.push_back(E) : ve1.push_back(E);
	F > 5 ? ve2.push_back(F) : ve1.push_back(F);

	// ���� ���� �ð��� ã�� ���̹Ƿ� ���� ����
	sort(ve1.begin(), ve1.end());
	sort(ve2.begin(), ve2.end());

	// ����ó�� (�ð����� ǥ���� �� ���� ���)
	if (ve2.size() >= 4 || (ve1[0] == 2 && ve1[1] > 3) || ve1[0] > 2) return "NOT POSSIBLE";

	// ve1�θ� ���
	if (ve2.size() == 0) {
		answer = to_string(ve1[0]) + to_string(ve1[1]) + ":" + to_string(ve1[2]) + to_string(ve1[3]) + ":" + to_string(ve1[4]) + to_string(ve1[5]);
	}
	// ve2�� ss��
	else if (ve2.size() == 1) {
		answer = to_string(ve1[0]) + to_string(ve1[1]) + ":" + to_string(ve1[2]) + to_string(ve1[3]) + ":" + to_string(ve1[4]) + to_string(ve2[0]);
	}
	// ve2�� mm, ss��
	else if (ve2.size() == 2) {
		answer = to_string(ve1[0]) + to_string(ve1[1]) + ":" + to_string(ve1[2]) + to_string(ve1[3]) + ":" + to_string(ve1[4]) + to_string(ve2[0]);
	}
	// ve2�� hh, mm, ss��
	else {
		answer = to_string(ve1[0]) + to_string(ve2[0]) + ":" + to_string(ve1[1]) + to_string(ve2[1]) + ":" + to_string(ve1[2]) + to_string(ve2[2]);
	}

	return answer;
}

int main() {
	printf("%s\n", solution(6, 6, 6, 6, 6, 6).c_str());
}