/*
* Complete the function below.
*/
int consecutive(long num) {

	long  s = 1, t = 1, cur = 1;
	int result = 0;
	int tmp = num / 2 + 1;

	while (s <= t && t <= num) {
		if (s >= tmp)
			break;
		if (cur < num) {
			t++;
			cur += t;
		}
		else if (cur == num) {
			result++;
			t++;
			cur += t;
		}
		else {
			cur -= s;
			s++;
		}
	}

	return result;
}