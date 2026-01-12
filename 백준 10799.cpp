#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string rod;
	cin >> rod;

	int cur_rod = 0;
	int count = 0;
	stack<char> S;
	bool rasor = true;

	for (auto k : rod) {
		if (k == '(') {
			S.push(k);
			count++;
			rasor = true;
		}
		else {
			if (rasor == true) {
				count--;
				S.pop();
				count += S.size();
				rasor = false;
			}
			else {
				S.pop();
				//count++;
			}
		}
	}

	cout << count;
}