#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> N;
	int top = 1;

	int check[1000005] = { 0 };
	int index_check = 0;
	int flag = 0;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k >= top) {
			while (top <= k) {
				N.push(top++);
				check[index_check++] = 1;
			}
		}

		if (N.top() == k) {
			if (!N.empty()) {
				N.pop();
				check[index_check++] = -1;
			}
		}
		else {
			flag = 1;
		}
	}

	if (flag == 1) cout << "NO\n";
	else {
		for (int i = 0; i < index_check; i++) {
			if (check[i] == 1) cout << "+\n";
			else if (check[i] == -1) cout << "-\n";
		}
	}
}