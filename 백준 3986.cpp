#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int count = 0;

	while (n--) {
		stack<char> S;

		string word;
		cin >> word;

		for (auto k : word) {
			if (!S.empty()) {
				if (S.top() != k) S.push(k);
				else S.pop();
			}
			else {
				S.push(k);
			}
		}

		if (S.empty()) count++;
	}

	cout << count;
}