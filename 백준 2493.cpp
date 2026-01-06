#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int >> N;

	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;

		while (!N.empty() && N.top().first < height) N.pop();

		if (N.empty()) cout << "0 ";
		else cout << N.top().second << " ";

		N.push({ height, i });
	}
}