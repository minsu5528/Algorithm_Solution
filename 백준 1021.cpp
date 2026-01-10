#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int m, n;
	cin >> m >> n;

	deque<int> DQ;
	for (int i = 1; i <= m; i++) DQ.push_back(i);

	int count = 0;
	while (n--) {
		int a;
		cin >> a;

		int index = 0;
		for (int i = 0; i < DQ.size(); i++) {
			if (DQ[i] == a) {
				index = i;
				break;
			}
		}

		if (index <= DQ.size() / 2) {
			while (DQ.front() != a) {
				DQ.push_back(DQ.front());
				DQ.pop_front();
				count++;
			}
		}
		else {
			while (DQ.front() != a) {
				DQ.push_front(DQ.back());
				DQ.pop_back();
				count++;
			}
		}

		DQ.pop_front();
	}

	cout << count;
}