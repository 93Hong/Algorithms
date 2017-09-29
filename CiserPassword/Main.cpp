#include<iostream>
#include<string>
using namespace std;

string caesar(string s, int n)
{
	string answer = "";

	n = (n % 26);

	for (int i = 0; i<s.length(); i++) {
		if (isalpha(s[i])) {
			if (islower(s[i]))
				if (s[i] + n > 'z')
					s[i] = s[i] + n - ('z' - 'a' + 1);
				else
					s[i] += n;
			else
				if (s[i] + n > 'Z')
					s[i] = s[i] + n - ('z' - 'a' + 1);
				else
					s[i] += n;
		}
	}

	return s;
}

int main()
{
	string text = "X Y Z x y z";
	int testNo = 30;

	printf("%d\n", 'z' - 'a' + 1);

	string testAnswer = caesar(text, testNo);

	cout << testAnswer;
}