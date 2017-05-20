#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int ans = 0;
	int len = 2 * w + 1;

	for (int i = 0; i < stations.size(); i++) {
		if (i == 0) {
			if (stations[i] - w - 1>0) {
				if ((stations[i] - w - 1) % len == 0)ans += (stations[i] - w - 1) / len;
				else ans += ((stations[i] - w - 1) / len) + 1;
			}
		}
		else {
			int lon = (stations[i] - w) - (stations[i - 1] + w) - 1;
			if (lon > 0) {
				if (lon%len == 0)ans += lon / len;
				else ans += (lon / len) + 1;
			}
		}
	}
	int last = n - (stations[stations.size() - 1] + w);
	if (last <= 0) return ans;
	else {
		if (last%len == 0)ans += last / len;
		else ans += (last / len) + 1;
		return ans;
	}
}